// code studio


// Expected Time Complexity: O(V + E).
// Expected Auxiliary Space: O(V).
#include<unordered_map>
#include<list>

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &visited ,
unordered_map<int, list<int> > &adj, vector<vector<int>> &result){

    visited[node] = true ;
    disc[node] = low[node] = timer++ ;

    for(auto neighbour: adj[node]){

        if(neighbour == parent) // then ignore it
            continue ;

        if(!visited[neighbour]){
            // step -> 1 call for dfs(neighbour)
            dfs(neighbour, node, timer, disc, low, visited, adj, result) ;

            // step -> 2 while returning from dfs call if ho skta h ki hume low[neighbour] ko upadte kiya ho dfs call m so low[node] updation is possible then update it
            low[node] = min(low[node], low[neighbour]) ;

            // step -> 3 now check that edge(node, neighbour) is a bridge or not
            if(low[neighbour] > disc[node]){ // that means it is a bridge
                vector<int> ans ;
                ans.push_back(node) ;
                ans.push_back(neighbour) ;
                result.push_back(ans) ;
            }
        }
        else{ // that means neighbour is visited or we can say that we already reach this neighbour via another path

            // back edge
            low[node] = min(low[node], disc[neighbour]) ;            
        }
    }
}


vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e){

    unordered_map<int, list<int> > adj ;

    for(int i=0 ; i<edges.size() ; i++){
        int u = edges[i][0] ;
        int v = edges[i][1] ;

        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    // required data structure & variable
    int timer = 0 ;
    int parent = -1 ;
    vector<int> disc(v, -1) ;
    vector<int> low(v, -1) ;
    unordered_map<int, bool> visited ;

    vector<vector<int>> result ;
    // call dfs
    for(int i=0 ; i<v ; i++){
        if(!visited[i])
            dfs(i, parent, timer, disc, low, visited, adj, result) ;
    }

    return result ;
}