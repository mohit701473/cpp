

// Approch 1 using level order traversal 
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).
    vector<int> rightView(Node *root)
    {
       vector<int> ans ;
        if(root == NULL)
            return ans ;
            
        map<int, int> nodes ; // first int indicate the level and the second int indicate the corrosponding right view node data
        queue<pair<Node* , int> > q ; // here int give level of the node
        
        q.push(make_pair(root, 0)) ;
        
        while(!q.empty()){
            
            pair<Node*, int> temp = q.front() ;
            q.pop() ;
            
            Node* tempNode = temp.first ;
            int lvl = temp.second ;
            
            nodes[lvl] = tempNode -> data ;
            
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
    void recursiveRightView(Node* root, int lvl, vector<int> &ans){
        
        if(root == NULL)
            return ;
            
        if(lvl == ans.size()){ // i.e. this level is not inserted into vector
            ans.push_back(root -> data) ;
        }
        
        // right recursive call
        recursiveRightView(root -> right, lvl+1, ans) ;
        
        // left recursive call
        recursiveRightView(root -> left, lvl+1, ans) ;
    }
    
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int> ans ;
        if(root == NULL)
        return ans ;
    
        int lvl = 0 ;
        recursiveRightView(root, lvl, ans) ;
        
        return ans ;
    }