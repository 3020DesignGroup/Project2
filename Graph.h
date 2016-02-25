//Wyatt Emery
//Talon Marquard
//Graph.h
//Project 2 Task 3
//2/24/16
//Stub Code

#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Vertex
{
public:

    Vertex();

    //Returns the vector of Edges in this Vertex
    vector<int> getEdges() const;

    string getName() const;

    void addEdge(int vertex);

private:
    //contains the indeces of the vertices that this Vertex has an edge with
    vector<int> _edges;
    string _name;
};


//Class Graph is designed only to create an undirected, acyclic, unweighted graph
//Each vertex object knows about which other Vertices it is connected via a vector 
//of indeces of those vertices
//edges are only implied thorugh this information that each vertex contains
class Graph
{
public:
    Graph();
    //added a destructor to handle dynamically constructed Vertices
    ~Graph();

    int getLongestPath() const;
    vector<Vertex> getVertices() const;

    void addVertex(Vertex vertex);

    //Adds an Edge between the specified vertices
    //Notice order of indeces does not matter due to undirection
    void addEdge(Vertex vertex1, Vertex vertex2);

    //Adds an edge between the specified indexes of vertices
    //Notice order of indeces does not matter due to undirection
    void addEdge(int index1, int index2);

private:
    vector<Vertex> _vertices;
};

//Vertex Function Definitions
Vertex::Vertex()
{

}

vector<int> Vertex::getEdges() const
{
        return _edges;
}

string Vertex::getName() const
{
        return _name;
}

void Vertex::addEdge(int vertex)
{
       
}

//Graph Function Definitions

Graph::Graph()
{

}

Graph::~Graph()
{

}

int Graph::getLongestPath() const
{
    return 0;
}

vector<Vertex> Graph::getVertices() const
{
    return _vertices;
}

void Graph::addVertex(Vertex vertex)
{

}
void Graph::addEdge(Vertex vertex1, Vertex vertex2)
{

}
void Graph::addEdge(int index1, int index2)
{

}