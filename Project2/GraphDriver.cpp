//Wyatt Emery
//Talon Marquard
//GraphDriver.cpp
//Project 2 Task 3
//2/24/16



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
void randBuildGraph(Graph& graph, int size);
void fileBuildGraph(Graph& graph, ifstream& infile);
string intToString(int intConvert);

int main()
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

    cout << "Longest Path in Tree is: " << longestPath << "\nand was found in " << timer() << " seconds" << endl;

    return 0;
}

bool getInput(Graph& graph)
{
    int size;
    string filename;
    ifstream infile;
    string option;

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
    for(int i = 0; i < size - 1; i++)
    {
        Vertex vertex(intToString(i));
        int numVertices = randReal(0, size - edgeIndex);
        for(int k = 0; k < numVertices; k++)
        {
            vertex.addEdge(edgeIndex);
            edgeIndex++;
        }
        graph.addVertex(vertex);
    }
    
    Vertex vertex(intToString(size-1));
    while(edgeIndex < size-1)
    {
        vertex.addEdge(edgeIndex);
        edgeIndex++;
    }
    graph.addVertex(vertex);
   
}

void fileBuildGraph(Graph& graph, ifstream& infile)
{
    
}

string intToString(int intConvert)
{
		std::ostringstream cstr;  //create the stream
		cstr << intConvert;  //put integer into the stream
		return cstr.str();  //put out the string
}
