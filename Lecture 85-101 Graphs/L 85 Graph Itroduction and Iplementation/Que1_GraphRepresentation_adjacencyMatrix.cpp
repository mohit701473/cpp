#include<iostream>
using namespace std ;

// S.C = O(n^2)  bcz storing a graph in a 2-D Matrix or Adjacency Matrix required space is Vertex*Vertex 

int main()
{
    int n , m ;
    cout<<"enter the no. of Nodes"<<endl;
    cin>>n ;
    cout<<"enter the no. of Edges"<<endl;
    cin>>m ;

    // Create a adjeancy matrix 
    int adj[100][100] = {0}; 
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++){
            cout<<adj[i][j]<<" " ;
        }
        cout<<endl;
    }

    for(int i = 0 ; i < m ; i++) {
        int u , v ;
        cout<<"enter the edge between Node u & v"<<endl;
        cin>> u >> v ;
        adj[u][v] = 1 ;
        adj[v][u] = 1 ;
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++){
            cout<<adj[i][j]<<" " ;
        }
        cout<<endl;
    }
}