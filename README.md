# Graph_lab 

This lab practices implementing graph algorithms in C++. 

## Provided files: 
  * Graph.h: define the Graph class
  * Graph.cpp: implemented memeber functions of Graph class
  * Graph_driver_file.cpp: the main() that reads graph (from standard input or file), performs selecetd graph traversal or algorithms as selected by the user.
  * Makefile: for compilation
  * Three sample graph files **directed_graph.txt**, **dressing.txt**, **undirected_graph.txt** each specifying a graph in the format expected by the program.


## Requirement:
  * Implement **BFS_Explore** function.
  * Implement **ShortestHopPath (NodeType s, NodeType d)** function, by using the **BFS_Explore** function.
  * Implement **DFS(NodeType s)**, DFS Traversal from the node s, recursively. 
  * Implement **IsConnected (NodeType s, NodeType t)** function.
  * Extend the given **DFS_Graph()** function to return a topological ordering of the nodes if the graph is Directed Acyclic Graph. 

## Extra credit opportunities: 
  * First extend the Graph class so that it can represent weighted graph, assocciating each edge with a real value, w.
  * Then implement a function **Dijkstra (NodeType s)** that calculate the minimum distance paths from source node s to other nodes in the graph. The function
    displays the **dist** and **pred** values for all nodes.
    
## What to submit: 

Submit your **Graph.cpp**, **Graph.h**, **Graph_driver.cpp** at the following link: 
TBA. 

This project is graded manually for correctness, and the previous "hand-grading" rubrics for coding style still apply. 
