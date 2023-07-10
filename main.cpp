// Driver Code
#include<iostream>
#include<fstream>
#include"spatial/Graph.hpp"
#include"mincut-maxflow/mincut.hpp"
int main()
{
	std::ifstream  GRAPH_COORDINATE("../data/NY_coordinate.txt");
	spatial::Graph g;
	long long verticesNum,node_id;
	GRAPH_COORDINATE>>verticesNum;
	std::cout<<verticesNum<<std::endl;
    double lat,lon;
	char occupy;
	GRAPH_COORDINATE>>occupy>>node_id>>lat>>lon;
	g.addNode(node_id,lat,lon);
	std::cout<<g.v2Coordinate[1].lat<<std::endl;
	// g.addEdge(0, 1, 4);
	// g.addEdge(0, 2, 2);
	// g.addEdge(1, 2, 1);
	// g.addEdge(1, 3, 2);
	// g.addEdge(2, 4, 2);
	// g.addEdge(1, 4, 4);
	// g.addEdge(3, 5, 3);
	// g.addEdge(4, 5, 3);
	
	
    
	
	//std::cout << g.DinicMaxflow(0,5)<<std::endl;
	//g.MinCut(0);
	return 0;
}