#include<bits/stdc++.h>
using namespace std ;

class TreeNode{
    private:
        int data ;
        vector<TreeNode*> children ;
    
    public:
        TreeNode(int d){
            this -> data = d ;
            this -> children = vector<TreeNode*> () ;
        }
};


int main(){
    int arr[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1} ;
    stack<TreeNode*> st ;
    TreeNode* root ;

    for(int i=0 ; i<24 ; i++){
        if(arr[i] == -1){
            st.pop() ;
        }else{
            TreeNode* temp = new TreeNode(arr[i]) ;
            if(!st.empty()){
                st.top() -> children.push_back(temp) ;
            }else{
                root = temp ;
            }

            st.push(temp) ;
        }
    }

    cout<<root -> data << endl;

    for(int i=0 ; i < root -> children.size() ; i++){
        TreeNode* temp = root -> children[i] ;
        cout << temp -> data <<" " ;
    }

}