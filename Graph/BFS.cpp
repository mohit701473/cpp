#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std ;

void Graph_BFS(int s , vector<int> adj[] , int n)
{
    // Mark all the vertices as not visited
    vector<bool> visited;
    visited.resize(n,false);
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    cout<<"BFS traversal"<<endl;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front(); 
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto adjecent: adj[s])
        {
            // cout<<"adjecent = "<<adjecent<<endl;
            if (!visited[adjecent])
            {
                visited[adjecent] = true;
                queue.push_back(adjecent);
            }
        }
    }
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


    int node ;
    cout<<"enter the node from which you want to BFS treversal start"<<endl;
    cin>>node ;
    Graph_BFS(node , adj , n) ;

}