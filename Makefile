all: graphLab



graphLab: Graph.o Graph_driver_file.o
	g++ -o graphLab Graph.o Graph_driver_file.o


wordCnt: unordered_map.cpp
	g++ -o wordCnt unordered_map.cpp

Graph.o: Graph.cpp Graph.h
	g++ -c -std=c++11 Graph.cpp


Graph_driver_file.o: Graph_driver_file.cpp Graph.h
	g++ -c -std=c++11 Graph_driver_file.cpp


clean: 
	rm *.o graphLab

