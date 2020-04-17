#include "Graph.h"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


void Graph::addEdge(string v1, string v2){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){ //if you find the name of the first one
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){ //don't wanna add edge between a city and itself so i!=j
                    adjVertex av; //instance of vertex 
                    av.v = &vertices[j];
                    vertices[i].adj.push_back(av);
                    //add another vertex in the other direction
                    adjVertex av2;
                    av2.v = &vertices[i];
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
    

}

void Graph::addVertex(string n){
    bool found = false;
    
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){ //don't want duplicates in graph
            found = true;
            cout << vertices[i].name << " already exists" << endl;
        }
    }
    
    if(!found){ //if you don't find then add a vertex
        vertex v;
        v.name = n;
        v.distance = 0;
        vertices.push_back(v); //inserts it into the vector 
    }
    
}

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<" --> ";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout << vertices[i].adj[j].v->name << " ";
        }
        cout<<endl;
    }

}

void Graph::breadthFirstTraverse(string sourceVertex){
    //Since we don't have a search function, implement here to find starting vertex
    //need a pointer to keep track of starting vertex
    vertex *vStart;
    
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == sourceVertex){
            vStart = &vertices[i];
        }
    }
    
    cout << "starting vertex (root): " << vStart->name << "->";
    //now we will print the vertices in their breadth first order exciting shit!
    
    vStart->visited = true;
    
    //Use the STL queue to keep track of the vertices to be visited
    queue<vertex*> q;
    
    //enqueue starting vertex
    q.push(vStart);
    
    //need another vertex pointer to keep track of the current vertex
    vertex *n;
    
    while(!q.empty()){
        //q dequeue 
        n = q.front(); //like a peek
        q.pop();
        
        for(int x = 0; x < n->adj.size(); x++){
            //check if the vertex has been visited
            if(! n->adj[x].v -> visited){
                n->adj[x].v -> distance = n->distance + 1;
                n->adj[x].v -> visited = true;
                q.push(n->adj[x].v);
                cout << n->adj[x].v->name << "(" << n->adj[x].v -> distance << ") ";
            }
            
        }
    }
    cout << endl;
    

}

