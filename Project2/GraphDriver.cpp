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

using namespace std;


bool getInput(Graph& graph);
void randBuildGraph(Graph& graph, int size);
void fileBuildGraph(Graph& graph, ifstream& infile);

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

}

void fileBuildGraph(Graph& graph, ifstream& infile)
{
    
}