namespace Base
{

    struct Node
	{
		int node_id; 
	
		double lat; 
		
		double lon; 
		
	};

	struct Edge
	{
		Node v; 
	
		int flow; 
		
		int capacity; 
		
		int u_index; 
	};

    
}
