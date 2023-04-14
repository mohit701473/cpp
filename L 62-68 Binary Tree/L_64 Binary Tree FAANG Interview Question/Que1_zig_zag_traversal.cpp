// ZigZag Tree Traversal


// Approch 1  using the level order traversal 
// T.C. = O(N)  N = no. of nodes 
// S.C. = O(N) N = no. of Node bcz we use queue and in comple binary tree all node of the last level are inserted into queue at same tmie
vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> ans ;
    	if(root == NULL)
    	    return ans ;
    	    
        queue<Node*> q ;
        q.push(root) ;
        
        bool leftToRight = true ; // this is a flag which tell us to in which direction we have to traverse
        
        while(!q.empty()){
            
            int size = q.size() ; // this will tell us the size the level
            vector<int> temp(size) ;
            
            for(int i=0 ; i<size ; i++){
                Node* tempNode = q.front() ;
                q.pop() ;
                
                // if leftToRight = true then normal flow i.e index = i else reverse flow i.e. index = size - i -1
                int index = leftToRight ? i : size - i - 1;
                temp[index] = tempNode -> data ;
                
                if(tempNode -> left != NULL) 
                    q.push(tempNode -> left) ;
                    
                if(tempNode -> right != NULL)
                    q.push(tempNode -> right) ;
            }
            
            // Change the direction of the traversal
            leftToRight = !leftToRight ;
            
            for(auto i: temp)
                ans.push_back(i) ;
        }
        return ans ;
    }