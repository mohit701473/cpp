
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).
vector<int> diagonal(Node *root)
{
   vector<int> ans ;
   if(root == NULL)
        return ans ;
        
    queue<Node*> q ;
    q.push(root) ;
    
    while(!q.empty()){
        Node* temp = q.front() ;
        q.pop() ;
        while(temp != NULL){
            ans.push_back(temp -> data) ;
            if(temp -> left)
                q.push(temp -> left) ;
            temp = temp -> right ;
        }
    }
    
    return ans ;
}