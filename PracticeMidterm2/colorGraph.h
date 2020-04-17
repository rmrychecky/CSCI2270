#ifndef COLORGRAPH_H
#define COLORGRAPH_H
#include<vector>
#include<iostream>

struct vertex;

struct adjVertex{
    vertex *v;

};

struct vertex{
    std::string name;
    bool visited;
    int distance;
    std::string color;
    std::vector<adjVertex> adj;
};

class Graph
{
    public:
        void addEdge(std::string v1, std::string v2);
        void addVertex(std::string name);
        void displayEdges();
        void breadthFirstTraverse(std::string sourceVertex);

    private:
        std::vector<vertex> vertices;

};

#endif 
