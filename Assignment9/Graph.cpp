#include "Graph.hpp"

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

Graph :: Graph(){
  
}

Graph :: ~Graph(){
  
}

void Graph :: addVertex(string cityName){
    bool found = false;
    
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == cityName){ //don't want duplicates in graph
            found = true;
            cout << vertices[i].name << " already exists" << endl;
        }
    }
    
    if(!found){ //if you don't find then add a vertex
        vertex v;
        v.name = cityName;
        vertices.push_back(v); //inserts it into the vector 
    }
}

void Graph :: addEdge(string city1, string city2, int distance){
      for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == city1){ //if you find the name of the first one
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == city2 && i != j){ //don't wanna add edge between a city and itself so i!=j
                    Edge av; //instance of vertex 
                    av.v = &vertices[j];
                    av.distance = distance;
                    vertices[i].Edges.push_back(av);
                }
            }
        }
    }
    
}

void Graph :: displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].Edges.size(); j++){
            if(j == vertices[i].Edges.size()-1){
                cout << vertices[i].Edges[j].v->name << " " << "(" << vertices[i].Edges[j].distance << " miles)";
            }
            else{
                cout << vertices[i].Edges[j].v->name << " " << "(" << vertices[i].Edges[j].distance << " miles)***";
            }
            
            
        }
        cout<<endl;
    }
}

void Graph :: printDFT(){
  setAllVerticesUnvisited(); 
  
 
  for(int i = 0; i < vertices.size(); i++){
      if(vertices[i].visited == false){
          DFT_traversal(&vertices[i]);
      }
  }
}

void Graph :: printBFT(){
  for(int i = 0; i < vertices.size(); i++){
      BFT_traversal(&vertices[i]);
  }
}

void Graph :: setAllVerticesUnvisited(){
  for(int i = 0; i < vertices.size(); i++){
        vertices[i].visited = false;
  }
}

vertex* Graph :: findVertex(string name){
    
  for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == name){
        return &vertices[i];
  }
}

return NULL;
}

void Graph :: BFT_traversal(vertex *v){
    vertex *vStart = v;
    
    if(vStart->visited != true){
        cout << vStart->name << endl;
    }
    
     
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
        
        for(int x = 0; x < n->Edges.size(); x++){
            //check if the vertex has been visited
            if(! n->Edges[x].v -> visited){
                n->Edges[x].distance = n->Edges[x].distance;
                n->Edges[x].v -> visited = true;
                q.push(n->Edges[x].v);
                cout << n->Edges[x].v->name << endl;
            }
            
        }
    }
}

void Graph :: DFT_traversal(vertex *v){

    v->visited = true;
    cout << v->name << endl;
    
    for(int i = 0; i < v->Edges.size(); i++){
        if(! v->Edges[i].v -> visited){
            DFT_traversal(v->Edges[i].v);
        }
    }
    
}

