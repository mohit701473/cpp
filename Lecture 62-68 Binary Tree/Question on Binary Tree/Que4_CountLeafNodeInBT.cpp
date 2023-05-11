// Count Leaf Node


int noOfLeafNodes(BinaryTreeNode<int> *root){
    queue<BinaryTreeNode<int>*> q ;
    q.push(root) ;

    int count = 0 ;
    while(!q.empty()){
        BinaryTreeNode<int>* temp = q.front() ;
        q.pop() ;

        if(temp -> left != NULL) {
            q.push(temp -> left) ;
        }

        if(temp -> right != NULL)
            q.push(temp -> right) ;

        if((temp -> left == NULL) && (temp -> right == NULL))
            count++ ;
    }

    return count ;
}