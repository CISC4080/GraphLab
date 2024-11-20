#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <assert.h>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;
#include "Graph.h"


//Create a graph object with the given nodes
//and initialize the adjacent lists to empty 
Graph::Graph (NodeType nodeArray[], int len, bool d)
{
	for (int i=0;i<len;i++)
	{
			nodes.push_back (nodeArray[i]);

			//Initialize adjacent list of nodes[i] to be an empty list 
			list<NodeType> emptyList;
			adjacentLists[nodeArray[i]] = emptyList;
	}
	directed = d;

}

/*
the text file specify a graph as follows:
      true
      5 A B C D E
      A -> B
      C -> D
      e -> A
      */
 void Graph::InitializeFromFile(string fileName){
	 ifstream input; 
	 string word;

	 cout <<"Loading graph from " << fileName<<endl;
	 input.open (fileName);
	 if (!input.is_open()){
		cout <<"Failed to open file " << fileName<<endl;
		exit(1);
	 }


	 //read a string, if it's "true" set directed to true;
	  //                if it's "false", set directed to false.
	  input >> word;
	  if (word=="true" || word=="TRUE")
		  directed = true;
	  else  if (word=="False" || word=="false" || word=="FALSE")
		  directed= false; 

	  cout <<"The file is " <<word<<endl;

	   //read an integer value (the number of vertices in the graph)
	  int nodeNum;
	 input >> nodeNum;
	 cout <<"With "<<nodeNum<<" nodes"<<endl;

	  /* for loop to read the given number of node
		for each node read in, store it in "nodes" vector,
		 and initialize the adjacent list for the node to empty
		 list
		 */
	 NodeType node;
	 for (int i=0;i<nodeNum;i++)
	 {
		input >> node;
		nodes.push_back (node);

		list<NodeType> emptyList;
		adjacentLists[node] = emptyList;
	 }

	//cout <<"Read edges!\n";
	 /*
	   read one edge a time (by reading one node, 
	   one string and another node)
	   and insert the edge into the graph by calling
	AddEdge
		*/
	 NodeType fromNode, toNode;
	 while (input >> fromNode >> word >> toNode)
	 {
		 /*
		cout <<"Read an edge" << fromNode << " "<<
			word<<" " <<toNode;
			*/
		
		AddEdge (fromNode, toNode);
	 }

	 //close the file
	input.close();
}

//Precondition: from and to nodes are in the vector of nodes 
//
void Graph::AddEdge (const NodeType & from, const NodeType & to)
{
	int cnt=0;
	int fromIndex, toIndex;

	//Find from and to nodes in the nodes vector 
	//three ways to iterate through a container class: 
	//  1) for (int i=0;i<nodes.size();i++)
	//  2) use iterator: see Display() member function for example
	//  3) range-for as used here 
	for (auto node:nodes)
	{
			if (node==from)
			{
				cnt++;
			} 
			if (node==to)
			{
				cnt++;
			}

	}

	//check precondition
	assert (cnt==2);

	adjacentLists[from].push_back(to);
	if (!directed) 
		adjacentLists[to].push_back (from);
		
}

/*
//return the adjacent list of node u 
list<NodeType> Graph::AdjacentNodes (const NodeType & u)
{
   	return adjacentLists[u]; 
}
*/

int Graph::FindNode (const NodeType & u)
{
	for (int i=0;i<nodes.size();i++)
        {
                 if (nodes[i]==u)
		    return i;
        }

	return -1;
}

void Graph::Display()
{
       list<NodeType>::iterator it; //this iterator, it, can be used to iterate through elements
                                    // in a list of NodeType 

	if (directed) 
		cout <<"Directed Graph:\n";
	else
		cout <<"Undirected Graph:\n";

	cout <<"Vertex: {";

	for (int i=0;i<nodes.size();i++)
	{
		cout <<nodes[i]<<"(out-degree="<<adjacentLists[nodes[i]].size()<<") ";
	}
	cout <<"}"<<endl;

	cout <<"Edges:\n{";
	for (int i=0;i<nodes.size();i++)
	{
		//Get the adjacent list of node i 
		list<NodeType> & adjList = adjacentLists[nodes[i]];

		//Iterate through each element in the adjacent list, adjList 
		//for (it=adjList.begin();it!=adjList.end();it++)
	        for (auto v:adjList) { //for each NodeType v in adjList 
			if (directed) 
				//cout <<"   " <<nodes[i]<<"->"<<*it<<","<<endl;
				cout <<"   " <<nodes[i]<<"->"<<v<<","<<endl;
			else
			{
				/*
				if (i<=FindNode((*it)))
					         // *it reference iterator, to obtain the NodeType 
					cout <<"   " <<nodes[i]<<"-"<<*it<<","<<endl;
					*/
				if (i <= FindNode (v)) //only display each edge once 
					cout <<"   " <<nodes[i]<<"-"<<v<<","<<endl;

			}
		}
	}
	cout <<"}\n";

}

//Explore and visit all vertices of the graph that are
//reachable from node s in BFS order
// When finish: Display
//     * the depth of all reachable vertices (i.e., shortest distance to s)
//     * the predecessors of all reachable vertices (BFS tree)
void Graph::BFS_Explore (NodeType s)
{

	
}

void Graph::DFS_Graph()
{

	//initialize color
	for (int i=0;i<nodes.size();i++)
	{
		color[nodes[i]]=White;
	}

	for (int i=0;i<nodes.size();i++){
		if (color[nodes[i]]==White) {
			DFS_FromSource (nodes[i]);
		}

	}

}

void Graph::DFS (NodeType src)
{
	stack<NodeType> s; //all grey nodes

        cout <<src<<" turns Gray"<<endl;
	color[src] = Gray;
	s.push (src);

	while (!s.empty()){
		NodeType curNode = s.top();
		NodeType neighbor;

		//find a White neighbor of curNode
		bool found=false;
		list<NodeType> adjNodes = adjacentLists[curNode];
		for (NodeType v:adjNodes){

			if (color[v]==White)
			{
				found=true;
				neighbor=v;
				break;
			}
		}
		if (found) {
			color[neighbor] = Gray;
                        cout <<neighbor <<" turns Gray"<<endl;
			s.push (neighbor);
		}
		else{
			color[curNode] = Black;
                        cout <<curNode <<" turns Black"<<endl;
			s.pop ();
		}
	}
}
