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
		int v; 
	
		int flow; 
		
		int capacity; 
		
		int u_index; 
	};

	class Graph
	{
		public:
		std::unordered_map<unsigned long long, Coordinate> V;
		void addNode(int nodeID, double lat, double lon);
	};
}