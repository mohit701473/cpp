// Vertical Traversal of Binary Tree

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        // First Initialize our veriable or Data Structure
        map<int, map<int, vector<int> > > nodes ;  // outer map store the mapping via HD while inner map store the mapping via level wise 
        queue<pair< Node* , pair<int , int> > > q ;
        vector<int> ans ;
        
        q.push(make_pair(root, make_pair(0,0))) ; // (0,0) bcz Horizontal Distance of root from root is = 0 and at starting we are at 0th level
        
        while(!q.empty()){
            
            pair<Node*, pair<int , int> > temp = q.front() ;
            q.pop() ;
            
            // Now find the values to fill the map nodes
            Node* frontNode = temp.first ; 
            int hd = temp.second.first ;
            int lvl = temp.second.first ;
            
            // push the data of teh front node according to the HD and level
            nodes[hd][lvl].push_back(frontNode -> data) ;
            
            if(frontNode -> left) // if left node exist then push into queue
                q.push(make_pair(frontNode -> left, make_pair(hd-1, lvl+1))) ;  // when we go to the left of the root then hd will decrese and for the child Node level will increse
                
            if(frontNode -> right) 
                q.push(make_pair(frontNode -> right, make_pair(hd+1, lvl+1))) ;  // when we go to the right of the root then hd will increase and for the child Node level will increse
        } 
        
        // Now we have to get out the ans from map and store into the ans vector
        for(auto i: nodes){
            for(auto j: i.second){
               for(auto k: j.second) {
                   ans.push_back(k) ;
               } 
            }
        }
        
        return ans ;
    }
};




// Leet Code Vertical Traversal of Binary Tree

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // First Initialize veriable and required data structure
        map<int, map<int, vector<int> > > nodes ;
        queue<pair<TreeNode*, pair<int, int> > > q ;
        vector<vector<int>> ans ;

        // insert first value into queue 
        q.push(make_pair(root, make_pair(0,0))) ; // at starting the Hd of the root from root is = 0 and we start from level 0

        while(!q.empty()){

            pair<TreeNode*, pair<int, int> > temp = q.front() ;
            q.pop() ;

            TreeNode* frontNode = temp.first ;
            // Now find the required input for the map nodes 
            int hd = temp.second.first ;
            int lvl = temp.second.second ;

            // Now insert/push the data of the frontNode into map
            nodes[hd][lvl].push_back(frontNode -> val) ;

            if(frontNode -> left != NULL)
                q.push(make_pair(frontNode -> left, make_pair(hd-1, lvl+1))) ; // hd-1 bcz for left node hd will decrese and lvl+1 bcz for child levele will increses

            if(frontNode -> right != NULL)
                q.push(make_pair(frontNode -> right, make_pair(hd+1, lvl+1))) ; // hd+1 bcz for right node hd will increase and lvl+1 bcz for child levele will increses

        }

        for(auto i: nodes){
            vector<int> tempVec ;
            for(auto j: i.second) {
                sort(j.second.begin(),j.second.end()) ;
                for(auto k: j.second){
                    tempVec.push_back(k) ;
                }
            }
            ans.push_back(tempVec) ;
        }        

        return ans ;
    }
};

