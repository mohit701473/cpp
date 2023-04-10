/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



// ---------------------------------------------------------  Preeorder Traversal -----------------------------------------------------------------

        // Approch 1 Itrative method
        // T.C. = O(N)  bcz we travers all nodes of the tree
        // S.C. = O(N)  when stack store all node at a time 
        class Solution {
        public:
            vector<int> preorderTraversal(TreeNode* root) {
                vector<int> ans ;

                if(root == NULL)
                    return ans ;

                stack<TreeNode*> s ;
                s.push(root) ;

                while(!s.empty()){
                    TreeNode* temp = s.top() ;
                    s.pop() ;
                    ans.push_back(temp -> val) ;

                    if(temp -> right != NULL)
                        s.push(temp -> right) ;

                    if(temp -> left != NULL)
                        s.push(temp -> left) ;
                }
                
                return ans ;
            }
        };

        // Approch 2 Recursive method
        // T.C. = O(N)  
        // S.C. = O(N)  here auxilary space is used by recursion call & N is here height and in worst case height can be no. of nodes
        class Solution {
        public:
            void solve(TreeNode* root, vector<int> &ans){
                if(root == NULL)
                    return ;

                ans.push_back(root -> val) ;
                solve(root -> left, ans) ;
                solve(root -> right, ans) ;
            }

            vector<int> preorderTraversal(TreeNode* root) {
                vector<int> ans ;

                if(root == NULL)
                    return ans ;
                solve(root, ans) ;
                
                return ans ;
            }
        };





//-----------------------------------------------------------  Inorder Traversal ------------------------------------------------------------------
        // Approch 1 Itrative Method
        // T.C. = O(N)  bcz we travers all nodes of the tree
        // S.C. = O(2N)  when stack store all node at a time
        class Solution {
        public:
            vector<int> inorderTraversal(TreeNode* root) {
                vector<int> ans ;
                if(root == NULL)
                    return ans ;

                stack<TreeNode*> s ;
                s.push(root) ;

                while(!s.empty()){

                    if(root == NULL){
                        root = s.top() ;
                        s.pop() ;
                        ans.push_back(root -> val) ;
                        root = root -> right ;
                    }

                    else {
                        root = root -> left ;
                    }

                    if(root != NULL){
                        s.push(root) ;
                    }
                }
                return ans ;
            }
        };


        // Approch 2 Recursive method
        // T.C. = O(N)  
        // S.C. = O(N)  here auxilary space is used by recursion call & N is here height and in worst case height can be no. of nodes
        class Solution {
        public:
            void solve(TreeNode* root, vector<int> &ans){
                if(root == NULL){
                    return ;
                }

                solve(root -> left, ans) ;
                ans.push_back(root -> val) ;
                solve(root -> right, ans) ;
            }

            vector<int> inorderTraversal(TreeNode* root) {
                vector<int> ans ;
                if(root == NULL)
                    return ans ;

                solve(root, ans) ;
                return  ans ;
            }
        };




// ----------------------------------------------------------  Postorder Traversal  ---------------------------------------------------------------

        // Approch 1 Itrative Method using 2 stack
        // T.C. = O(N)  bcz we travers all nodes of the tree
        // S.C. = O(N)  when stack store all node at a time
        class Solution {
        public:
            vector<int> postorderTraversal(TreeNode* root) {
                vector<int> ans ;
                if(root == NULL)
                    return ans ;

                stack<TreeNode*> st1 ;
                stack<TreeNode*> st2 ; // storing the postorder of the tree
                st1.push(root) ;

                while(!st1.empty()){
                    root = st1.top() ;
                    st1.pop() ;

                    if(root -> left != NULL)
                        st1.push(root -> left) ;
                    
                    if(root -> right != NULL) 
                        st1.push(root -> right) ;
                    
                    st2.push(root) ;
                }

                while(!st2.empty()){
                    ans.push_back(st2.top() -> val) ;
                    st2.pop() ;
                }
                
                return ans ;
            }
        };
        
        
        // Approch 2 Itrative Method using 1 stack


        class Solution {
        public:
            vector<int> postorderTraversal(TreeNode* root) {
                vector<int> ans ;
                if(root == NULL)
                    return ans ;

                stack<TreeNode*> st ;
                TreeNode* curr = root ;

                while(curr != NULL || !st.empty()){
                    
                    if(curr != NULL){
                        st.push(curr) ;
                        curr = curr -> left ;
                    }

                    else{
                        TreeNode* temp = st.top() -> right ;
                        if(temp == NULL){
                            temp = st.top() ;
                            st.pop() ;
                            ans.push_back(temp -> val) ;
                            while(!st.empty() && temp == st.top() -> right){
                                temp = st.top() ;
                                st.pop() ;
                                ans.push_back(temp -> val) ;
                            }
                        }
                        else {
                            curr = temp ;
                        }
                    }
                }

                return ans ;
            }
        };


        // Approch 3  Recursive method
        // T.C. = O(N)  
        // S.C. = O(N)  here auxilary space is used by recursion call & N is here height and in worst case height can be no. of nodes

        class Solution {
        public:

            void solve(TreeNode* root, vector<int> &ans){
                if(root == NULL)
                    return ;

                solve(root -> left, ans) ;
                solve(root -> right, ans) ;
                ans.push_back(root -> val) ;
            }


            vector<int> postorderTraversal(TreeNode* root) {
                vector<int> ans ;
                if(root == NULL)
                    return ans ;

                solve(root, ans) ;
                return ans ;
            }
        };



