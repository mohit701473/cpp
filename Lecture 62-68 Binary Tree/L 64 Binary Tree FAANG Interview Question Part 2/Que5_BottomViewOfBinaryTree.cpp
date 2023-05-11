
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).
vector <int> bottomView(Node *root) {
        vector<int> ans ;
        if(root == NULL)
            return ans ;
            
        map<int, int> nodes ; // first int will store hd and second int will store corosponding node data
        queue<pair<Node* , int> > q ;
        
        q.push(make_pair(root, 0)) ;
        
        while(!q.empty()){
            
            pair<Node*, int> temp = q.front() ;
            q.pop() ;
            
            Node* tempNode = temp.first ;
            int hd = temp.second ;
            
            nodes[hd] = tempNode -> data ;
            
            if(tempNode -> left)
                q.push(make_pair(tempNode -> left, hd-1)) ;
                
            if(tempNode -> right)
                q.push(make_pair(tempNode -> right, hd+1)) ;
        }
        
        for(auto i: nodes)
            ans.push_back(i.second) ;
            
        return ans ;
    }