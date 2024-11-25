#include <iostream>
#include <vector>
#include <list>
#include <assert.h>
#include "Graph.h"

using namespace std;

int main()
{

	cout <<"Welcome! This program is an interactive graph demo program!\n";

	Graph curGraph;
        string command, fileName;

        do {
		cout <<"Enter a command (BuildGraph, LoadFromFile, BFS, DFS, ShortestHop, IsConnected, TopoSort, Quit):";
		cin >> command;

		if (command=="BuildGraph") {
			cout <<"Build a graph from standard input\n";
	
			 cout <<"Enter the number of nodes in the graph:";
        		int N;
        		do{ 
                		cin >> N;
        		} while (N<=0);

        		//Read in nodes 
        		string * nodes = new string[N];
        		for (int i=0;i<N;i++)
        		{
                		cout <<"Enter "<<i<<"-th node (a string): ";
                		cin >> nodes[i];
        		}       

        		//Directed or not 
        		cout <<"Is it directed or not (Y/N)";
        		char answer;
        		do {
           				cin >> answer;
        		} while (answer!='Y' && answer!='N');

        		Graph graph(nodes,N,answer=='Y');
                                        //if answer=='Y' directed 

			//read in edges 
        		cout <<"Enter the number of edges: ";
        		int M;
        		do {
                		cin >> M;
        		} while (M<0);

        		string fromNode, toNode;
        		for (int i=0;i<M;i++)
        		{
                		cout <<"Enter the "<<i<<"-th edge: from which node:";
                		cin >> fromNode;
                		cout <<"to which node:";
                		cin >> toNode;

                		graph.AddEdge (fromNode, toNode);
        		}

        		graph.Display();

			curGraph = graph;
		}
		else if (command=="LoadFromFile"){

			cout <<"Which file do you want to load (directed_graph.txt, dressing.txt)?";
			cin >> fileName; 

			//string graphFile2(fileName);
			//cout <<"The file name is" << graphFile2<<endl;
			Graph G;
		
			G.InitializeFromFile (fileName);

			curGraph = G; 
			curGraph.Display();
		}
		else if (command=="BFS"){
			cout <<"Enter the node to start BFS from:";
			NodeType srcNode;
			cin >> srcNode;
			if (curGraph.FindNode (srcNode)==-1)
				cout <<"There is no node "<<srcNode<<" in the graph\n";
			else
				curGraph.BFS_Explore (srcNode);

		} else if (command=="DFS"){
			curGraph.DFS_Graph();
		} 
          

		//Todo: add support for command: ShortestHop, IsConnected, TopoSort... 

	} while (command!="Quit" && command!="quit");

	cout <<"Bye!\n";
}
