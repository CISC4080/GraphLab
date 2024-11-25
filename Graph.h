#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <string>
#include <assert.h>

using namespace std;
typedef string NodeType;

//A graph where each node is a string 
class Graph{
public:

	Graph(){
		directed=true;
	}

	//Create a graph object with the given nodes
	//and initialize the adjacent lists to empty 
	Graph (NodeType nodeArray[], int len, bool d);

	/* load a graph from a text file which specifies a graph in the 
	 * following format 
      true
      5 A B C D E 
      A -> B
      C -> D
      e -> A
      */
      void InitializeFromFile(string fileName); 

	//Precondition: from and to nodes are in the vector of nodes 
	void AddEdge (const NodeType & from, const NodeType & to);

	//return the adjacent list of node u 
	//list<NodeType> AdjacentNodes (const NodeType & u);

	int FindNode (const NodeType & u);

	void Display();

        //Todo #1: Implement this function
	//Explore and visit all vertices of the graph that are
	//reachable from node s in BFS order
	// When finish: Display
	//     * the depth of all reachable vertices (i.e., shortest distance to s)
	//     * the predecessors of all reachable vertices (BFS tree)
	void BFS_Explore (NodeType s);

	// DFS traveral of the graph:
	// Keep:
	//  Choose a node that has not been explored
	//  performing DFS traversal from that node
	// unitl all nodes are explored
	void DFS_Graph ();

	// DFS traversal from node s 
	void DFS (NodeType s); //DFS traversal from s, implemented withour recursion

        //Todo #2: implement this function. 
        void DFS_recursive (NodeType s);

        
	//Todo #3: Implement this function. Hint: call BFS_Explore(s), and then
	// use the pred to construct the path 
	//Return the shortes hop path from s to d, if there is no path, return 
	// an empty vector
	vector<NodeType> ShortestHopPath (NodeType s, NodeType d); 


	//Todo #4: Implement s_t_connect using DFS traversal 
        //Return true if there is a path from node s to node t
        bool IsConnected (NodeType s, NodeType t); 

	//Todo #5: Extend DFS_Graph, so that it returns a topological order of the graph
        // if the graph IS DAG as a vector of NodeType
	

private:
	bool directed; //true: directed graph, false: undirected graph 

	vector<NodeType> nodes;

	//For a node u, 
	//adjacentLists[u] is the adjacent list of node u
	//
	//for undirected graph, we store each edge twice, for example,
	// if node a and b are connected by an edge, 
	//   b is in the adjacent list of a, and a is in the adjacent list of b
	unordered_map<NodeType, list<NodeType>> adjacentLists; 

	//Data Structures used by BFS and DFS 
	typedef enum Color{
                White=0,
                Gray=1,
                Black=2} Color;
        unordered_map<NodeType,int> d; //the depth/hop count of all nodes from s for BFS, 
				//discover time for DFS
        unordered_map<NodeType,NodeType> pred; // pred[u] is the node that leads us to u
        unordered_map<NodeType,Color> color; //color[u] will be White, Gray, Black

};

