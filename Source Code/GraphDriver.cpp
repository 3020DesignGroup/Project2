//Wyatt Emery
//Talon Marquard
//GraphDriver.cpp
//Project 2 Task 4
//3/2/16



#include"Graph.h"
#include"RandomUtilities.h"
#include"winTimer.h"
#include<iostream>
#include<fstream>
#include<string>
#include <cstdlib>
#include <cstdio>
#include <sstream>

using namespace std;


bool getInput(Graph& graph);
//builds a random acyclic undirected unweighted graph based upon the size inputted
//
void randBuildGraph(Graph& graph, int size);

//Warning: filebuildgraph does not check input for cycles nor does it prevent them.
//It is the file creator's job to make sure the graph is acyclic. If the graph has
//a cycle the program will crash
void fileBuildGraph(Graph& graph, ifstream& infile);
string intToString(int intConvert);
void printGraph(Graph graph);

int main()
{
	while (true)
	{
		Graph graph;
		int longestPath;
		bool going = getInput(graph);
		while (!going)
		{
			going = getInput(graph);
		}

		Timer timer;
		timer.start();
		longestPath = graph.getLongestPath();
		timer.stop();

		cout << endl << "Longest Path in Tree is: " << longestPath << "\nand was found in " << timer() << " seconds" << endl << endl;

		//Debug function
		//printGraph(graph);
		//system("pause");
	}
	return 0;
}

bool getInput(Graph& graph)
{
	int size;
	string filename;
	ifstream infile;
	string option;
	randomizeSeed();

	//prompt for random or file entry.
	cout << "Enter r for random filling of the tree. Enter f for input via external file: ";
	cin >> option;
	if (option == "r")
	{
		//prompt for size
		cout << "please enter desired size: ";
		cin >> size;

		randBuildGraph(graph, size);
		return true;
	}

	// fill the graph by file input
	else if (option == "f")
	{
		//prompt for file
		cout << "enter filename: ";
		cin >> filename;

		//open file
		infile.open(filename);
		if (!(infile.is_open()))
		{
			cerr << "File not found!" << endl << endl;
			return false;
		}

		fileBuildGraph(graph, infile);
		return true;
	}
	else
	{
		cerr << "unrecognized input. Please enter \"r\" or \"f\"" << endl << endl;
		return false;
	}
	return true;
}

void randBuildGraph(Graph& graph, int size)
{
	int edgeIndex = 0;
	for (int i = 0; i < size; i++)
	{
		Vertex vertex(intToString(i));
		int numVertices = randInt(1, 100);
		for (int k = 0; k < numVertices; k++)
		{
			if (edgeIndex > i && edgeIndex < size)
				vertex.addEdge(edgeIndex);
			edgeIndex++;
		}
		graph.addVertex(vertex);
	}
}

void fileBuildGraph(Graph& graph, ifstream& infile)
{
	int size;
	infile >> size;
	int data = 0;
	string name;
	for (int i = 0; i < size; i++)
	{
		infile >> name;
		Vertex vertex(name);
		infile >> data;
		while (data != -1)
		{
			vertex.addEdge(data);
			infile >> data;
		}
		graph.addVertex(vertex);
	}

}

string intToString(int intConvert)
{
	std::ostringstream cstr;  //create the stream
	cstr << intConvert;  //put integer into the stream
	return cstr.str();  //put out the string
}

void printGraph(Graph graph)
{
	vector<Vertex> vertices = graph.getVertices();
	for (int i = 0; i < vertices.size(); i++)
	{
		cout << vertices[i].getName() << "\t";
		vector<int> edges = vertices[i].getEdges();
		for (int k = 0; k < edges.size(); k++)
		{
			cout << " " << edges[k] << " ";
		}
		cout << endl;
	}
}