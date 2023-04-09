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



// -----------------------------------------------------------Preeorder Traversal -----------------------------------------------------------------

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



