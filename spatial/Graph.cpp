#include <unordered_map>

#include"Graph.hpp"


namespace spatial
{
    void Graph::addNode(int nodeID, double lat, double lon)
    {
        Coordinate a{lat, lon };
        Graph::v2Coordinate[nodeID]=a;
    }
    void Graph::addEdge(int u, int v)// we do not need capacity for inertial-flow
	{
        // all the capacity should be set as 1
		// Forward Base::Edge : 0 flow and capacity capacity
		Edge a{ v, 0, 1, (int)adj[v].size() };
		
		// Back Base::Edge : 0 flow and 0 capacity
		Edge b{ u, 0, 0, (int)adj[u].size() };
		
		adj[u].push_back(a);
		adj[v].push_back(b); // reverse spatial::Edge
	}
}

