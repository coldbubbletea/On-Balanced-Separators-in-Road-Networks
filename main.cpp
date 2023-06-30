// Driver Code
#include"Spatial/Graph.hpp"
int main()
{
	
	Graph g(6);
	

		
	g.addEdge(0, 1, 4);
	g.addEdge(0, 2, 2);
	g.addEdge(1, 2, 1);
	g.addEdge(1, 3, 2);
	g.addEdge(2, 4, 2);
	g.addEdge(1, 4, 4);
	g.addEdge(3, 5, 3);
	g.addEdge(4, 5, 3);
	
	
    
	
	std::cout << g.DinicMaxflow(0,5)<<std::endl;
	g.MinCut(0);
	return 0;
}