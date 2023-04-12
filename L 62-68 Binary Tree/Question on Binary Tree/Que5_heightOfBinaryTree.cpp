/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

// Approch 1 Recursive method
// T.C. = O(n) bcz we traverse each node at once and we can't reduce this T.C. bcz we have to traverse all Nodes 
// S.C. = O(height) bcz in recursive call stack no of call is equal to the height of the tree but in worst case S.C. = O(n) when tree is a skewed tree
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){ 
         if(node == NULL)
            return 0 ;

        int leftHeight = height(node -> left) ;
        int rightHeight = height(node -> right) ;

        int ans = max(leftHeight, rightHeight) + 1 ;

        return ans ;
    }
};


// Approch 2 using level order traversal
// T.C. = O(n)  bcz we travers all Node at once
// S.C. = O(n)  bcz in worst case when tree is Full Binary tree then in the last level no. of Nodes = n/2 and they all are in queue at a same time 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0 ;
        
        queue<TreeNode*> q ;
        q.push(root) ;
        q.push(NULL) ; // Bcz first level Nodes are pushed into queue

        int height = 0 ;

        while(!q.empty()) {
            TreeNode* temp = q.front() ;
            q.pop() ;

            if(temp == NULL){ // temp = NULL mean previous level is completed
                height++ ;
                if(!q.empty())
                    q.push(NULL) ; // push NULL into queue bcz all left & right child of the previous level are inserted into queue
            }

            else{
                if(temp -> left != NULL)
                    q.push(temp -> left) ;

                if(temp -> right != NULL) 
                    q.push(temp -> right) ;
            }
        }

        return height ;
    }
};