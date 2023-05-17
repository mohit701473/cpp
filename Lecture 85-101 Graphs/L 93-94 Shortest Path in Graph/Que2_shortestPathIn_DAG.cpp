#include<iostream>
#include<unordered_map>
#include<stack>
#include<list>
#include<vector>
#include<limits.h>

// T.C. = O(V+E)
// S.C. = O(V+E)

using namespace std ;

class Graph{
    public:
    unordered_map<int, list<pair<int, int> > > adj ;
    //  vector<pair<int, int> adj[]   we can also use this


    void addEdge(int u, int v, int weight){
        pair<int, int> p = make_pair(v, weight) ;

        adj[u].push_back(p) ;
    } 

    void printAdj(){

        for(auto i: adj){
            cout<< i.first << " -> ";
            for(auto j: i.second){
                cout<< "(" << j.first << "," << j.second <<") ";
            }
            cout<<endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &topo){

        visited[node] = true ;

        for(auto neighbour: adj[node]){
            if(!visited[neighbour.first])
                dfs(neighbour.first, visited, topo) ;
        }

        topo.push(node) ;
    }

    void getShortestPath(int src, vector<int> &distance, stack<int> &topo){
        distance[src] = 0 ;

        while(!topo.empty()){
            int top = topo.top() ;
            topo.pop() ;

            if(distance[top] != INT_MAX){ 
                // Do process
                for(auto i: adj[top]){
                    if( distance[i.first] >  distance[top] + i.second) { // d[v] > d[u] + weight
                        // upadte d[v] ;
                        distance[i.first] = distance[top] + i.second ;
                    }
                }

            }
        }
    }
};



int main()
{
    Graph g ;

    g.addEdge(0,1,5) ;
    g.addEdge(0,2,3) ;
    g.addEdge(1,2,2) ;
    g.addEdge(1,3,6) ;
    g.addEdge(2,3,7) ;
    g.addEdge(2,4,4) ;
    g.addEdge(2,5,2) ;
    g.addEdge(3,4,-1) ;
    g.addEdge(4,5,-2) ;

    g.printAdj() ;


    int V = 6 ; 

// step -> 1
    // Topological sort
    unordered_map<int, bool> visited ;
    stack<int> topo ;

    for(int i=0 ; i<V ; i++){
        if(!visited[i])
            g.dfs(i, visited, topo) ;
    }

// step -> 2
    int src = 1 ;
    vector<int> distance(V) ;

    for(int i=0 ; i<V ; i++)
        distance[i] = INT_MAX ;

    g.getShortestPath(src, distance, topo) ;

    cout<< "answer is: "<<endl;

    for(int i=0 ; i<V ; i++){
        cout<<distance[i] << " " ;
    }cout<<endl;
}