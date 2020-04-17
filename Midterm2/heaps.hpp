#ifndef HEAP_HPP
#define HEAP_HPP

class Heap
{
	public:

	/*
	class constructor
	Purpose: perform all operations necessary to instantiate a class
	object
	Parameter headSize: Maximum size of the heap
	return: none
	*/
	Heap(int heapSize);
	/*
	class destructor
	Purpose: free all resources that the object has acquired
	Parameters: none
	return: none
	*/
	~Heap();
	
	/*
	Method Name: printHeap
	Purpose: Print the heap array as it is.
	returns void
	*/
	void printHeap();

	/*
	Method Name: addToHeap
	Purpose: Add a new value to the heap and make sure the heap property is maintained
	returns void
	*/
	void addToHeap (float value);
	/*
	Method Name: removeFromHeap
	Purpose: remove the value at the front of the heap, 
	call other method(s) as required to maintain heap
	Parameters: none
	return: The first value of print
	*/
	float removeFromHeap();
	/*
	Method Name: peekValue
	Purpose: return the root of the heap
	Parameters: none
	return: the first element of heap
	*/
	float peekValue();
	/*
	Method Name: isFull
	Purpose: indicate if the heap is full
	Parameters: none
	return: true if queue is full, false otherwise
	*/
	bool isFull();
	/*
	Method Name: isEmpty
	Purpose: indicate if the heap is empty
	Parameters: none
	return: true if queue is empty, false otherwise
	*/
	bool isEmpty();

	private:

	/*
	Method Name: parent
	Purpose: return the parent for the nodeIndex
	Parameter nodeIndex - index of node
	return: int
	*/
	int parent(int nodeIndex);
	
	/*
	Method Name: leftChild
	Purpose: return the leftChild for the nodeIndex
	Parameter nodeIndex - index of node
	return: int
	*/
	int leftChild(int nodeIndex);
	
	/*
	Method Name: rightChild
	Purpose: return the rightChild for the nodeIndex
	Parameter nodeIndex - index of node
	return: int
	*/
	int rightChild(int nodeIndex);
	
	/*
	Method Name: repairUpward
	Purpose: maintain heap properties by swapping node with parent if necessary
	Parameter nodeIndex - index of node that may violate heap properties
	return: void
	*/
	void repairUpward(int nodeIndex);
	/*
	Method Name: repairDownward
	Purpose: maintain heap properties by swapping node with child if necessary
	Parameter: nodeIndex - index of node that may violate heap properties
	return: void
	*/
	void repairDownward(int nodeIndex);

	float* heap; //pointer to the array 
	int currentSize; //current number of students in heap
	int heapSize; //maximum capacity of the heap
};
#endif











#include <bits/stdc++.h> 
using namespace std; 
  
// Utility bfs method to fill distance vector and returns 
// most distant marked node from node u 
int bfsWithDistance(vector<int> g[], bool mark[], int u,  
                                        vector<int>& dis) 
{ 
    int lastMarked; 
    queue<int> q; 
  
    //  push node u in queue and initialize its distance as 0 
    q.push(u); 
    dis[u] = 0; 
  
    //  loop untill all nodes are processed 
    while (!q.empty()) 
    { 
        u = q.front();      q.pop(); 
        //  if node is marked, update lastMarked variable 
        if (mark[u]) 
            lastMarked = u; 
  
        // loop over all neighbors of u and update their  
        // distance before pushing in queue 
        for (int i = 0; i < g[u].size(); i++) 
        { 
            int v = g[u][i]; 
              
            //  if not given value already 
            if (dis[v] == -1) 
            { 
                dis[v] = dis[u] + 1; 
                q.push(v); 
            } 
        } 
    } 
    //  return last updated marked value 
    return lastMarked; 
} 
  
// method returns count of nodes which are in K-distance  
// range from marked nodes 
int nodesKDistanceFromMarked(int edges[][2], int V,  
                             int marked[], int N, int K) 
{ 
    //  vertices in a tree are one more than number of edges 
    V = V + 1; 
    vector<int> g[V]; 
  
    //  fill vector for graph 
    int u, v;     
    for (int i = 0; i < (V - 1); i++) 
    { 
        u = edges[i][0]; 
        v = edges[i][1]; 
  
        g[u].push_back(v); 
        g[v].push_back(u); 
    } 
  
    //  fill boolean array mark from marked array 
    bool mark[V] = {false}; 
    for (int i = 0; i < N; i++) 
        mark[marked[i]] = true; 
  
    //  vectors to store distances 
    vector<int> tmp(V, -1), dl(V, -1), dr(V, -1); 
  
    //  first bfs(from any random node) to get one  
    // distant marked node 
    u = bfsWithDistance(g, mark, 0, tmp); 
  
    /*  second bfs to get other distant marked node  
        and also dl is filled with distances from first 
        chosen marked node */
    u = bfsWithDistance(g, mark, u, dl); 
  
    //  third bfs to fill dr by distances from second  
    // chosen marked node 
    bfsWithDistance(g, mark, u, dr); 
  
    int res = 0; 
    //  loop over all nodes 
    for (int i = 0; i < V; i++) 
    { 
        // increase res by 1, if current node has distance  
        // less than K from both extreme nodes 
        if (dl[i] <= K && dr[i] <= K) 
            res++; 
    } 
    return res; 
} 
  
// Driver code to test above methods 
int main() 
{ 
    int edges[][2] =  
    { 
        {1, 0}, {0, 3}, {0, 8}, {2, 3}, 
        {3, 5}, {3, 6}, {3, 7}, {4, 5}, 
        {5, 9} 
    }; 
    int V = sizeof(edges) / sizeof(edges[0]); 
      
    int marked[] = {1, 2, 4}; 
    int N = sizeof(marked) / sizeof(marked[0]); 
  
    int K = 3; 
    cout << nodesKDistanceFromMarked(edges, V, marked, N, K); 
    return 0; 
} 