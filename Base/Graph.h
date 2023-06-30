#include<vector>


namespace Base
{
	struct Node
	{
		int node_id; 
		double lat; 
		double lon; 
			
	}

	class Graph
	{
		std::vector<Node> V;
		void addNode(int nodeID, double lat, double lon);
	}
}