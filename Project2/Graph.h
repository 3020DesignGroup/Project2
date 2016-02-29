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
    Vertex(string name);

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
    //returns the index of the vertex passed if it exists in the 
    //_vertices vector. If it does not exist -1 is returned. O(n)
    //Uses the vertex name and edges to determine equality
    int findVertex(Vertex vertex);
};

//Vertex Function Definitions
Vertex::Vertex()
{
    _name = "Default Name";
}

Vertex::Vertex(string name)
{
    _name = name;
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
    if(vertex >= 0)
    _edges.push_back(vertex);
}

//Graph Function Definitions

Graph::Graph()
{
    //nothing needs to be done
}

int Graph::getLongestPath() const
{
    //STUB
    return 0;
}

vector<Vertex> Graph::getVertices() const
{
    return _vertices;
}

void Graph::addVertex(Vertex vertex)
{
    _vertices.push_back(vertex);
}
void Graph::addEdge(Vertex vertex1, Vertex vertex2)
{
    int index = findVertex(vertex2);
    if(index > -1)
    {
         vertex1.addEdge(index);
    }
}
void Graph::addEdge(int index1, int index2)
{
    if(index1 < _vertices.size() && index1 >= 0)
    {
        Vertex vertex = _vertices[index1];
        vertex.addEdge(index1); 
    }
}

//Private Helper Functions
int Graph::findVertex(Vertex vertex)
{
    for(int i = 0; i < _vertices.size(); i++)
    {
        //Using names and edges of vertices to determine equality
        if(_vertices[i].getName() == vertex.getName())
        {
           Vector<int> edges1 =  _vertices[i].getEdges();
           Vector<int> edges2 = vertex.getEdges();
           bool found == false;
           int i = 0;
           while(looking && i < edges2.size())
           {
                if(edges1[i] != edges2[i])
                {
                    looking == false;
                }
                i++;
           }
           if(looking == true)
           {
               return i;
           }
        }
    }
    return -1;
}
