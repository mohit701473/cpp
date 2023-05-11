class Solution {
  public:
  
    // This function will done two things 
    // first it will create node to parent mapping
    // second it wiil rturn target node or we can say it will find target node
    Node* createParentMapping(Node* root, int target, map<Node*, Node*>& nodeToParent){
        
        Node* targetNode = NULL ;
        
        // Now we tarverse tree by level order traversal
        queue<Node*> q ;
        q.push(root) ;
        nodeToParent[root] = NULL ; // create mapping for root node 
        
        while(!q.empty()) {
            Node* front = q.front() ;
            q.pop() ;
            
            if(front -> data = target)
                targetNode = front ;
                
            if(front -> left){
                nodeToParent[front -> left] = front ;
                q.push(front -> left) ;
            }
            
            if(front -> right){
                nodeToParent[front -> right] = front ;
                q.push(front -> right) ;
            }
        }
        
        return targetNode ;
    }
    
    
    int burnTree(Node* root, map<Node*, Node*>& nodeToParent){
        
        map<Node*, bool> visited ; // this keeps the track of the visited nodes
        queue<Node*> q ; // this is for level order traversal 
        
        q.push(root) ;
        visited[root] = true ;
        
        int time = 0 ;
        
        while(!q.empty()){
            bool flag = false ; // by this we can find is any addition is done in queue or not
            int size = q.size() ;
            
            for(int i=0 ; i<size ; i++){
                // process neighbouring nodes
                Node* front = q.front() ;
                q.pop() ;
                
                // check for left neighbour
                if(front -> left && !visited[front -> left]) {
                    flag = true ; // i.e. addition in queue is done 
                    q.push(front -> left) ;
                    visited[front -> left] = true ;
                }
                
                // check for right neighbour
                if(front -> right && !visited[front -> right]) {
                    flag = true ; // i.e. addition in queue is done 
                    q.push(front -> right) ;
                    visited[front -> right] = true ;
                }
                
                // check for parent 
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag = true ;
                    q.push(nodeToParent[front]) ;
                    visited[nodeToParent[front]] = true ;
                }
            }
            
            if(flag == true){
                time++ ;
            }
        }
        
        return time ;
    }
  
    int minTime(Node* root, int target) 
    {
        // Algo
        // step -> 1:  Create parent to node mapping
        // step -> 2:  find the target node
        // step -> 3:  burn tree in min time
        
        map<Node*, Node*> nodeToParent ;
        Node* targetNode = createParentMapping(root, target, nodeToParent) ;
        //cout<<targetNode -> data <<endl;
        
        int time = burnTree(targetNode, nodeToParent) ;
        
        return time ;
    }
};