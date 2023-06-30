#include <unordered_map>

#include"Graph.hpp"


namespace spatial
{
    void Graph::addNode(int nodeID, double lat, double lon)
    {
        Coordinate a{lat, lon };
        Graph::V[nodeID]=a;
    }
}
