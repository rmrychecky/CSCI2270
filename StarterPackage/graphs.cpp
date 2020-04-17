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

Graph :: Graph(){
  
}

Graph :: ~Graph(){
  
}

void Graph :: addEdge(int v1, int v2){
    vertex *h = findVertex(v1);
    vertex *k = findVertex(v2);
    
    h->Edges.push_back(k);
}

void Graph :: addVertex(int id1){
    bool found = false;
    
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].id == id1){ //don't want duplicates in graph
            found = true;
            cout << vertices[i].id << " already exists" << endl;
        }
    }
    
    if(!found){ //if you don't find then add a vertex
        vertex v;
        v.id = id1;
        vertices.push_back(v); //inserts it into the vector 
    }
}

void Graph :: displayEdges(){
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].id<<"-->";
        for(int j = 0; j < vertices[i].Edges.size(); j++){
            cout << vertices[i].Edges[j]->id << " ";
        }
        cout<<endl;
    }
}

void Graph :: printDFT(){
  setAllVerticesUnvisited(); 
  
 
  for(int i = 0; i < vertices.size(); i++){
      if(vertices[i].visited == false){
          DFTraversal(&vertices[i]);
      }
  }
}

void Graph :: printBFT(){
  for(int i = 0; i < vertices.size(); i++){
      BFTraversal(&vertices[i]);
  }
}

void Graph :: setAllVerticesUnvisited(){
  for(int i = 0; i < vertices.size(); i++){
        vertices[i].visited = false;
  }
}

vertex* Graph :: findVertex(int id1){
    
  for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].id == id1){
            return &vertices[i];
        }
  }

  return NULL;
}

void Graph :: BFTraversal(vertex *v){
    vertex *vStart = v;
    
    if(vStart->visited != true){
        cout << vStart->id << endl;
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
            if(! n->Edges[x] -> visited){
                n->Edges[x] -> visited = true;
                q.push(n->Edges[x]);
                cout << n->Edges[x]->id << endl;
            }
            
        }
    }
}

void Graph :: DFTraversal(vertex *v){

    v->visited = true;
    cout << v->id << endl;
    
    for(int i = 0; i < v->Edges.size(); i++){
        if(! v->Edges[i] -> visited){
            DFTraversal(v->Edges[i]);
        }
    }
    
}
