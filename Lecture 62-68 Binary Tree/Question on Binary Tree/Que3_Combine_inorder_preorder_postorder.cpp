#include<bits/stdc++.h>
using namespace std ;

struct TreeNode{
    int data ;
    TreeNode* left ;
    TreeNode* right ;

    // constructor
    TreeNode(int d) {
        this -> data = d ;
        this -> left = NULL ;
        this -> right = NULL ;
    }
};

TreeNode* buildTree(TreeNode* root) {
    int data ;
    cout<<"enter data"<<endl;
    cin>> data ;

    if(data == -1) 
        return NULL ;
    
    root = new TreeNode(data) ;

    // Insert into left of the current root 
    root -> left = buildTree(root -> left) ;

    // Insert into right of the current root
    root -> right = buildTree(root -> right) ;

    return root ;
}

// T.C. = O(3N)  bcz we are traversing all nodes thrice
// S.C. = O(4N)  bcz we using stack and 3 vector
void In_Pre_Post_order(TreeNode* root,  vector<int> &inorder, vector<int> &preorder, vector<int> &postorder) {

    if(root == NULL)
        return ;

    stack<pair<TreeNode*, int> > s ;
    pair<TreeNode*, int> curr = {root, 1} ;
    s.push(curr) ;

    while(!s.empty()) {
        pair<TreeNode*, int> temp ;
        
        temp.first = s.top().first ;
        temp.second = s.top().second ;
        s.pop() ;

        if(temp.second == 1){
            temp.second++ ;
            s.push(temp) ;
            preorder.push_back(temp.first -> data) ;

            if(temp.first -> left != NULL){
                temp.first = temp.first -> left ;
                temp.second = 1 ;
                s.push(temp) ;
            }
        }

        else{
            if(temp.second == 2){
                temp.second++ ;
                s.push(temp) ;
                inorder.push_back(temp.first -> data) ;

                if(temp.first -> right != NULL){
                    temp.first = temp.first -> right ;
                    temp.second = 1 ;
                    s.push(temp) ;
                }
            }

            else{
                if(temp.second == 3) {
                    postorder.push_back(temp.first -> data) ;
                }
            }
        }
    }
}


void recursive_inorder(TreeNode* root){ // left root right
    if(root == NULL)
        return ;

    recursive_inorder(root -> left) ;
    cout<<root -> data<<" ";
    recursive_inorder(root -> right) ;
}

void recursive_preorder(TreeNode* root){ // root left right
    if(root == NULL)
        return ;

    cout<<root -> data<<" ";
    recursive_preorder(root -> left) ;
    recursive_preorder(root -> right) ;
}


void recursive_postorder(TreeNode* root){ // left right root
    if(root == NULL)
        return ;

    recursive_postorder(root -> left) ;
    recursive_postorder(root -> right) ;
    cout<<root -> data<<" ";
}



int main()
{
    struct TreeNode* root = NULL ;   // 1 3 7 -1 -1 11 -1 -1 5  17 -1 -1 -1

    root = buildTree(root) ;

    vector<int> inorder ;
    vector<int> preorder ;
    vector<int> postorder ;

    In_Pre_Post_order(root, inorder, preorder, postorder) ;

//------------------- preorder -----------------------
    cout<<"recursive preorder"<<endl;
    recursive_preorder(root) ;
    cout<<endl;

    cout<<"preorder"<<endl;
    for(auto it: preorder) {
        cout<<it<<" " ;
    }cout<<endl<<endl;


//------------------- inorder -----------------------
    cout<<"recursive inorder"<<endl;
    recursive_inorder(root) ;
    cout<<endl;

    cout<<"inorder"<<endl;
    for(auto it: inorder) {
        cout<<it<<" " ;
    }cout<<endl<<endl;


//------------------- postorder -----------------------
    cout<<"recursive postorder"<<endl;
    recursive_postorder(root) ;
    cout<<endl;

    cout<<"postorder"<<endl;
    for(auto it: postorder) {
        cout<<it<<" " ;
    }cout<<endl<<endl;

    
}