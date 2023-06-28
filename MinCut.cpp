#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include <utility>
#include<queue>
#include<set>
namespace Base
{
	struct Edge
	{
		int v; 
	
		int flow; 
		
		int capacity; 
		
		int u_index; 
	};
}




// Residual Graph
class Graph {
public:
	int V; // number of vertex
	int* level; // stores level of a node
	std::vector<Base::Edge>* adj;
	

	Graph(int V)
	{
		adj = new std::vector<Base::Edge>[V];
		this->V = V;
		level = new int[V];
	}
	
	// add Base::Edge to the graph
	void addEdge(int u, int v, int capacity)
	{
		// Forward Base::Edge : 0 flow and capacity capacity
		Base::Edge a{ v, 0, capacity, (int)adj[v].size() };
		
		// Back Base::Edge : 0 flow and 0 capacity
		Base::Edge b{ u, 0, 0, (int)adj[u].size() };
		
		adj[u].push_back(a);
		adj[v].push_back(b); // reverse Base::Edge
	}
	
	bool BFS(int s, int t);
	int sendFlow(int s, int flow, int t, long long unsigned int ptr[]);
	int DinicMaxflow(int s, int t);
	std::pair<std::set<int>,std::set<int>> MinCut(int s);
};





// Finds if more flow can be sent from s to t.
// Also assigns levels to nodes.
bool Graph::BFS(int s, int t)
{
	for (int i = 0; i < V; i++)
		level[i] = -1;
	
	level[s] = 0; // Level of source vertex
	
	// Create a queue, enqueue source vertex
	// and mark source vertex as visited here
	// level[] array works as visited array also.
	std::list<int> q;
	q.push_back(s);
	
	std::vector<Base::Edge>::iterator i;
	while (!q.empty()) {
		int u = q.front();
		q.pop_front();
		for (i = adj[u].begin(); i != adj[u].end(); i++) {
			Base::Edge& e = *i;
			if (level[e.v] < 0 && e.flow < e.capacity) {
				// Level of current vertex is,
				// level of parent + 1
				level[e.v] = level[u] + 1;
				
				q.push_back(e.v);
			}
		}
	}
	
	// IF we can not reach to the sink we
	// return false else true
	return level[t] < 0 ? false : true;
}








// A DFS based function to send flow after BFS has
// figured out that there is a possible flow and
// constructed levels. This function called multiple
// times for a single call of BFS.
// flow : Current flow send by parent function call
// start[] : To keep track of next Base::Edge to be explored.
//           start[i] stores  count of edges explored
//           from i.
//  u : Current vertex
//  t : Sink
int Graph::sendFlow(int u, int flow, int t, long long unsigned int start[])
{
	// Sink reached
	if (u == t)
		return flow;
	
	// Traverse all adjacent edges one -by - one.
	for (; (long long unsigned int)start[u] != adj[u].size(); start[u]++) {
		// Pick next Base::Edge from adjacency list of u
		Base::Edge& e = adj[u][start[u]];
		
		if (level[e.v] == level[u] + 1 && e.flow < e.capacity) {
			// find minimum flow from u to t
			int curr_flow = std::min(flow, e.capacity - e.flow);
			
			int temp_flow = sendFlow(e.v, curr_flow, t, start);
			
			// flow is greater than zero
			if (temp_flow > 0) {
				// add flow  to current Base::Edge
				e.flow += temp_flow;
				
				// subtract flow from reverse Base::Edge
				// of current Base::Edge
				adj[e.v][e.u_index].flow -= temp_flow;
				//std::cout<<adj[e.v][e.u_index].flow<<std::endl;
				return temp_flow;
			}
		}
	}
	
	return 0;
}

//return a the list of cut edges in form of a list of std::pair
int Graph::DinicMaxflow(int s, int t)
{
	// Corner case
	if (s == t)
		return -1;
	
	int total = 0; // Initialize result
	
	// Augment the flow while there is path from source to sink, if no path then stop.
	while (BFS(s, t) == true) {
		// store how many edges are visited
		// from V { 0 to V }
		long long unsigned int* start = new long long unsigned int[V + 1]{ 0 };
		
		// while flow is not zero in graph from s to t
		while (int flow = sendFlow(s, INT_MAX, t, start)) {
			
			// Add path flow to overall flow
			total += flow;
		}
		
		// Remove allocated array
		delete[] start;
	}
	
	// return maximum flow
	return total;
}



 std::pair<std::set<int>,std::set<int>> Graph::MinCut(int s)
{
	std::queue<int> q;
	std::set<int> s1,s2;
	for(auto i=0;i<adj[s].size();++i)
	{
		std::cout<<adj[s][i].capacity-adj[s][i].flow<<std::endl;
		if((adj[s][i].capacity-adj[s][i].flow)>0)
		{
			q.push(adj[s][i].v);
			s1.insert(adj[s][i].v);
		}
	}
	while(int tmp=q.front())
	{
		q.pop();
		for(auto i=0;i<adj[tmp].size();++i)
		{
			
			if((adj[tmp][i].capacity-adj[tmp][i].flow)>0)
			{
				
				q.push(adj[tmp][i].v);
				s1.insert(adj[tmp][i].v);
			}
		}
	}
	for(auto i=s1.begin();i!=s1.end();i++)
	{
		std::cout<<*i<<std::endl;
	}
	return std::make_pair(s1,s2);
}






// Driver Code
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



