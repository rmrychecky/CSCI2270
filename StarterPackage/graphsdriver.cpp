#include "graphs.hpp"
#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <queue>
#include <list>
using namespace std;

int main()
{
    Graph g;
    
    g.addVertex(5);
    g.addVertex(6);
    g.addVertex(9);
    g.addVertex(8);
    g.addVertex(3);
    g.addVertex(2);
    
    g.addEdge(5, 2);
    g.addEdge(6, 2);
    g.addEdge(8, 3);
    g.addEdge(9, 2);
    g.addEdge(5, 6);
    g.addEdge(3, 6);
    g.addEdge(2, 3);
    
    //g.displayEdges();
    //g.printDFT();
    g.printBFT();
    return 0;
}