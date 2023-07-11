// Driver Code
#include<iostream>
#include<fstream>
#include"spatial/Graph.hpp"
#include"mincut-maxflow/mincut.hpp"
int main()
{
	std::ifstream  GRAPH_COORDINATE("../data/NY_coordinate.txt");
	minCut g(10);
	long long verticesNum,node_id;
	GRAPH_COORDINATE>>verticesNum;
	std::cout<<verticesNum<<std::endl;
    double lat,lon;
	char occupy;
	GRAPH_COORDINATE>>occupy>>node_id>>lat>>lon;
	g.addNode(node_id,lat,lon);
	std::cout<<g.v2Coordinate[1].lat<<std::endl;
	// if we staet an inertial-flow we should start from 1
	// as in multi-source and multi-sink problem we should set the virtual source as 0
	g.addEdge(0, 1, 99999);
	g.addEdge(0, 2, 99999);
	g.addEdge(1, 3, 1);
	g.addEdge(1, 4, 1);
	g.addEdge(2, 5, 1);
	g.addEdge(2, 6, 1);
	g.addEdge(3, 7, 1);
	g.addEdge(4, 7, 1);
	g.addEdge(5, 8, 1);
	g.addEdge(6, 8, 1);
	g.addEdge(7, 9, 99999);
	g.addEdge(8, 9, 99999);
	
    
	
	std::cout << g.DinicMaxflow(0,9)<<std::endl;
	g.MinCut(0);
	return 0;
}