#include<iostream>
#include<unordered_map>
#include<list>

using namespace std ;

// Time and space complexity for adjacency matrix is O(n^2) where n is the no of vertices. while for adjacency list time complexity is O(m) and space complexity is O(n+m) where n is no of vertices and m is no of edges.

template <typename T>
class Graph{
    public:
    unordered_map<T, list<T> > adj ;

    void addEdge(T u, T v, int direction){
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph 

        adj[u].push_back(v) ;

        if(direction == 0)
            adj[v].push_back(u) ;
    }

    void printAdjList(){
        for(auto i: adj){
            cout<<i.first << " -> ";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};


int main()
{
    Graph<char>  g;

    int n ;
    cout<<"enter the no. of Nodes"<<endl;
    cin>> n ;

    int m ;
    cout<<"enter the no. of edges"<<endl;
    cin>> m ;

    cout<<"enter the edges"<<endl;
    for(int i=0 ; i<m ; i++){
        char u, v ;
        cin>> u >> v ;
        g.addEdge(u, v, 0) ;
    }

    g.printAdjList() ;
}