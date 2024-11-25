CC=g++
CFLAGS=-g -O0 -Wall -std=c++11

all: graphLab


graphLab: Graph.o Graph_driver_file.o
	$(CC) -o graphLab $(CFLAGS) Graph.o Graph_driver_file.o

Graph.o: Graph.cpp Graph.h
	 $(CC) $(CFLAGS) -c  Graph.cpp


Graph_driver_file.o: Graph_driver_file.cpp Graph.h
	 $(CC) $(CFLAGS) -c  Graph_driver_file.cpp


clean: 
	rm *.o graphLab

