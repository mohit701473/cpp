#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std ;

void dfs(int node , vector<int> adj[] , int vis[] , vector<int> &ls) {
    vis[node] = 1 ;
    ls.push_back(node) ;

    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it , adj , vis , ls) ;
        }
    }
}



vector<int> dfsOfGrapf(int v , vector<int> adj[]) {
    int vis[v] = {0} ;
    int start = 0 ;
    vector<int> ls ;
    dfs(start , adj , vis , ls) ;
    return ls ;
}


int main() 
{
    int n , m ;
    cout<<"enter the no. of Nodes"<<endl;
    cin>>n ;
    cout<<"enter the no. of Edges"<<endl;
    cin>>m ;

    vector<int> adj[100] ;

    for (int v = 0 ; v < n ; ++v) {
        cout << "\n Adjacency list of vertex " << v
             <<endl ;
        for (auto x : adj[v])
            cout << x << "-> " ;
        cout<<endl;
    }


    for(int i = 0 ; i < m ; i++) {
        int u , v ;
        cout<<"enter the edge between Node u & v"<<endl;
        cin>> u >> v ; 
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    for (int v = 0 ; v < n ; ++v) {
        cout << "\n Adjacency list of vertex " << v
             <<endl ;
        for (auto x : adj[v])
            cout << x << "-> " ;
        cout<<endl;
    }


    // int node ;
    // cout<<"enter the node from which you want to BFS treversal start"<<endl;
    // cin>>node ;
    // Graph_BFS(node , adj , n) ;

    vector<int> ls = dfsOfGrapf(n , adj) ;
    cout<<"DFS treversal"<<endl;
    for(auto x : ls){
        cout<<x<<" ";
    }
}