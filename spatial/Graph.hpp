#ifndef GRAPH_HPP_
#define GRAPH_HPP_
#include<vector>
#include <unordered_map>
namespace spatial
{

	struct Coordinate
	{
		double lat; 
		double lon; 	
	};


    struct Edge
	{
		int node_id; 
	
		int flow; 
		
		int capacity; 
		
		int u_index; 
	};

	class Graph
	{
		public:
		long long vNum=0; //init value of vNum should be 0
		std::unordered_map<unsigned long long, Coordinate> v2Coordinate;
		std::vector<Edge>* adj;
		void addNode(int nodeID, double lat, double lon);
		void addEdge(int u, int v, int capacity);
	};
}

#endif 