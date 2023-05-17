
// T.C. = O(V^2)
// S.C. = O(V)
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> key(V, INT_MAX) ;
        vector<bool> mst(V, false) ;
        vector<int> parent(V, -1) ;
        int sum = 0 ;
        
        // process
        
        key[0] = 0 ;
        parent[0] = -1 ;
        
        for(int i=0 ; i<V ; i++){
            
            // step -> 1 find the minimum from key array && mst = false for that value ;
            int mini = INT_MAX ;
            int u ;
            for(int j=0 ; j<V ; j++){
                if(mst[j] == false && key[j] < mini){
                    u = j ;
                    mini = key[j] ;
                }
            }
            
            // step -> 2 markr mast[u] = true ;
            mst[u] = true ;
            
            // step -> process for adjacent of u
            for(auto neighbor: adj[u]){
                int v = neighbor[0] ;
                int weight = neighbor[1] ;
                
                if(mst[v] == false && key[v] > weight){
                    // upadte key aaray and parent array
                    key[v] = weight ;
                    parent[v] = u ;
                }
            }
        }
        
        for(auto i: key)
            sum += i ;

            
        return sum ;
    }
};