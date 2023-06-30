#include"Graph.h"


namespace Spatial
{
    void Graph::addNode(int nodeID, double lat, double lon)
    {
        // Forward Base::Edge : 0 flow and capacity capacity
        Base::Edge a{ v, 0, capacity, (int)adj[v].size() };
            
        // Back Base::Edge : 0 flow and 0 capacity
        Base::Edge b{ u, 0, 0, (int)adj[u].size() };
            
        adj[u].push_back(a);
        adj[v].push_back(b); // reverse Base::Edge
    }

}


