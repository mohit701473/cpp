// Left View of Binary Tree


// Approch 1 using level order traversal
// Expected Time Complexity: O(N*log(N)).
// Expected Auxiliary Space: O(N).
vector<int> leftView(Node *root)
{
   vector<int> ans ;
        if(root == NULL)
            return ans ;
            
        map<int, int> nodes ; // first int indicate the level and the second int indicate the corrosponding left left view node data
        queue<pair<Node* , int> > q ; // here int give level of the node
        
        q.push(make_pair(root, 0)) ;
        
        while(!q.empty()){
            
            pair<Node*, int> temp = q.front() ;
            q.pop() ;
            
            Node* tempNode = temp.first ;
            int lvl = temp.second ;
            
            //if the level is present in the map as a key value so do nothing
            if(nodes.find(lvl) == nodes.end()){
                nodes[lvl] = tempNode -> data ;
            }
            
            
            if(tempNode -> left)
                q.push(make_pair(tempNode -> left, lvl+1)) ;
                
            if(tempNode -> right)
                q.push(make_pair(tempNode -> right, lvl+1)) ;
        }
        
        for(auto i: nodes)
            ans.push_back(i.second) ;
            
        return ans ;
}


// Approch 2 using recursion
// T.C. = O(N) 
// S.C. = O(N) 
void recursiveLeftView(Node* root, int lvl, vector<int> &ans){
    
    if(root == NULL)
        return ;
        
    
    if(lvl == ans.size()){ // i.e. this level is not inserted into vector or we reach new level
        ans.push_back(root -> data) ;
    }
    
    // left recursive call
    recursiveLeftView(root -> left, lvl+1, ans) ;
    
    // right recursive call
    recursiveLeftView(root -> right, lvl+1, ans) ;
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   vector<int> ans ;
   
   if(root == NULL)
        return ans ;
    
    int lvl = 0 ;
    recursiveLeftView(root, lvl, ans) ;
    
    return ans ;
}