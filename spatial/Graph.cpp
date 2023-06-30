#include"Graph.hpp"


namespace spatial
{
    void Graph::addNode(int nodeID, double lat, double lon)
    {
        Node a{ nodeID, lat, lon };
        Graph::V.push_back(a);
    }
}
