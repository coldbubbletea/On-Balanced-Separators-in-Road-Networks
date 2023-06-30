#include<vector>


namespace spatial
{
	struct Node
	{
		int node_id; 
		double lat; 
		double lon; 	
	};

	class Graph
	{
		public:
		std::vector<Node> V;
		void addNode(int nodeID, double lat, double lon);
		Graph(int numOfVertices)
		{
			auto inputV = new std::vector<Node>[numOfVertices];
			this->V = *inputV;
		}
	};
}