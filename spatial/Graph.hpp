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
		long long vNum;
		std::unordered_map<unsigned long long, Coordinate> v2Coordinate;
		void addNode(int nodeID, double lat, double lon);
	};
}

#endif 