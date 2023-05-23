

bool detectLoop(Node* head) {

    if(head == NULL) {
        return false ;
    }

    map<Node* , bool> visited ;

    Node* temp = head ;

    while(temp != NULL) {

        // Condition if cycle is present 
        if(visited[temp] == true) {
            return true ;
        }

        visited[temp] = true ;
        temp = temp -> next ;
    }

    return false ;

    // T.C = O(n) bcz we traverse all Node at lest one time 
    // S.C = O(n) bcz we store every Node in map which required space 
}

Node* floydCycleDetection(Node* head)
    {
        // your code here
        
        if(head == NULL || head -> next == NULL) {
            return NULL ;
        }
        
        Node* slow = head ;
        Node* fast = head ;
        
        do {
            slow = slow -> next ;
            fast = fast -> next -> next ;
            
            if(fast == NULL || fast -> next == NULL) {
                return NULL ;
            }
        }while(slow != fast) ;
        
        return slow ;

    // T.C = O(n) bcz we traverse all Node at lest one time 
    // S.C = O(1) 
    }


Node* getStartingNode(Node* head) {

    if(head == NULL) {
        return NULL ;
    }

    Node* intersection = floydCycleDetection(head) ;
    Node* curr ;

    while(curr != intersection) {
        curr = curr -> next ;
        intersection = intersection -> next ;
    }

    return curr ;
}




    void removeLoop(Node* head)
    {
        // code here
        if(head == NULL || head -> next == NULL) {
            return ;
        }
        // just remove the loop without losing any nodes
        
        
        // Remove loop from linked list
        Node* curr = head ;
        Node* prev = NULL ;
        Node* temp = floydCycleDetection(head) ;
        
        if(temp == NULL) {
            return ;
        }
        
        if(curr != temp) {
            while(curr != temp) {
                curr = curr -> next ;
                prev = temp ;
                temp = temp -> next ;
            }
            
            prev -> next = NULL ;
        }
        
        else {
            do {
                prev = temp ;
                temp = temp -> next ;
            }while(temp != curr) ;
            
            prev -> next = NULL ;
        }
        
        return ;
        
    }