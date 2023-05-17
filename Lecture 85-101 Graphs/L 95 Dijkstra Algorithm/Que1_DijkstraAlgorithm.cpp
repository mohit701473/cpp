

class Solution
{
	public:
	
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V) ;
        set<pair<int, int> > st ; // set<pair<weight, node> > 
        
        for(int i=0 ; i<V ; i++){
            dist[i] = INT_MAX ;
        }
        
        dist[S] = 0 ;
        st.insert(make_pair(0, S)) ;
        
        while(!st.empty()){
            
            // top node nikal lo or minimum node nikal lo
            auto top = *(st.begin()) ;
            
            int nodeDistance = top.first ; // d[u]
            int topNode = top.second ;   
            
            // erase top record 
            st.erase(st.begin()) ;
            
            // traverse on neighbour 
            for(auto neighbour: adj[topNode]){
                //for(auto neighbour: i){
                    
                    int v = neighbour[0] ;
                    int weight = neighbour[1] ;
                     
                    if(dist[v] > dist[topNode] + weight){ // neighbour[1] => weight
                        
                        auto record = st.find(make_pair(dist[v], neighbour[0])) ;
                        
                        if(record != st.end())
                            st.erase(record) ;
                            
                        //update distance
                        dist[v] = dist[topNode] + weight ;
                        
                        st.insert(make_pair(dist[v], neighbour[0]));
                    }
                        
                //}
            }
        }
        
        return dist ;
        
    }
};

