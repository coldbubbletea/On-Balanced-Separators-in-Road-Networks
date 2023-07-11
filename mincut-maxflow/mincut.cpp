#include"mincut.hpp"






// Finds if more flow can be sent from s to t.
// Also assigns levels to nodes.
bool minCut::BFS(int s, int t)
{
	for (int i = 0; i < vNum; i++)
		level[i] = -1;
	
	level[s] = 0; // Level of source vertex
	
	// Create a queue, enqueue source vertex
	// and mark source vertex as visited here
	// level[] array works as visited array also.
	std::list<int> q;
	q.push_back(s);
	
	std::vector<spatial::Edge>::iterator i;
	while (!q.empty()) {
		int u = q.front();
		q.pop_front();
		for (i = adj[u].begin(); i != adj[u].end(); i++) {
			spatial::Edge& e = *i;
			if (level[e.node_id] < 0 && e.flow < e.capacity) {
				// Level of current vertex is,
				// level of parent + 1
				level[e.node_id] = level[u] + 1;
				
				q.push_back(e.node_id);
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
int minCut::sendFlow(int u, int flow, int t, long long unsigned int start[])
{
	// Sink reached
	if (u == t)
		return flow;
	
	// Traverse all adjacent edges one -by - one.
	for (; (long long unsigned int)start[u] != adj[u].size(); start[u]++) {
		// Pick next Base::Edge from adjacency list of u
		spatial::Edge& e = adj[u][start[u]];
		
		if (level[e.node_id] == level[u] + 1 && e.flow < e.capacity) {
			// find minimum flow from u to t
			int curr_flow = std::min(flow, e.capacity - e.flow);
			
			int temp_flow = sendFlow(e.node_id, curr_flow, t, start);
			
			// flow is greater than zero
			if (temp_flow > 0) {
				// add flow  to current Base::Edge
				e.flow += temp_flow;
				
				// subtract flow from reverse Base::Edge
				// of current Base::Edge
				adj[e.node_id][e.u_index].flow -= temp_flow;
				return temp_flow;
			}
		}
	}
	
	return 0;
}

//return a the list of cut edges in form of a list of std::pair
int minCut::DinicMaxflow(int s, int t)
{
	// Corner case
	if (s == t)
		return -1;
	
	int total = 0; // Initialize result
	
	// Augment the flow while there is path from source to sink, if no path then stop.
	while (BFS(s, t) == true) {
		// store how many edges are visited
		// from vNum { 0 to vNum }
		long long unsigned int* start = new long long unsigned int[vNum + 1]{ 0 };
		
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



 std::pair<std::set<int>,std::set<int>> minCut::MinCut(int s)
{
	std::queue<int> q;
	std::set<int> s1,s2;
	for(auto j=0;j<8;j++)
	for(auto i=0;i<adj[j].size();++i)
	{
		std::cout<<"j: "<<j<<std::endl;
		std::cout<<"flow "<<adj[s][i].flow<<std::endl;
		if((adj[s][i].capacity-adj[s][i].flow)>0)
		{
			q.push(adj[s][i].node_id);
			s1.insert(adj[s][i].node_id);
		}
	}
	while(int tmp=q.front())
	{
		q.pop();
		for(auto i=0;i<adj[tmp].size();++i)
		{
			
			if((adj[tmp][i].capacity-adj[tmp][i].flow)>0)
			{
				
				q.push(adj[tmp][i].node_id);
				s1.insert(adj[tmp][i].node_id);
			}
		}
	}
	//std::cout<<s1.size()<<std:endl;
	for(auto i=s1.begin();i!=s1.end();i++)
	{
		std::cout<<*i<<std::endl;
	}
	return std::make_pair(s1,s2);
}










