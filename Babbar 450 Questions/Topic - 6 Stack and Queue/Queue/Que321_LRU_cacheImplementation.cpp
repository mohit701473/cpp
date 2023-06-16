// LeetCode -> 146. LRU Cache
https://leetcode.com/problems/lru-cache/description/



// Expected Time Complexity: O(1) for both get() and set().
// Expected Auxiliary Space: O(1) for both get() and set(). 
// (Although, you may use extra space for cache storage and implementation purposes).
class LRUCache {
    class Node{
    public:
        pair<int, int> nodeVal;
        Node* next ;
        Node* prev ;

        Node(pair<int, int> p){
            this -> nodeVal = p ;
            next = prev = NULL ;
        }
    };

    int size ;
    Node *head, *tail ;
    unordered_map<int, Node*> m ;

    void print(Node* head){
        Node* curr = head ;

        while(curr != NULL){
            cout<<"["<<curr -> nodeVal.first<<","<<curr -> nodeVal.second<<"]"<<"," ;
            curr = curr -> next ;
        }cout<<endl;
    }

public:
    LRUCache(int capacity) {
        size = capacity ;
        head = tail = NULL ;
    }
    
    int get(int key) {
        if(m.find(key) == m.end())
            return -1 ;

        Node* temp = m[key] ;
        pair<int, int> ans = temp -> nodeVal ;

        if(temp == head){
            return ans.second ;
        }

        if(temp == tail){
            tail = temp -> prev ;
            if(tail != NULL && tail -> next != NULL)
                tail -> next = NULL ;
            m.erase(ans.first) ;
            delete temp ;
            put(ans.first, ans.second) ;
            return ans.second ;
        }

        if(temp != NULL && temp -> prev != NULL && temp -> next != NULL){
            temp -> prev -> next = temp -> next ;
            temp -> next -> prev = temp -> prev ;
        }
        m.erase(ans.first) ;
        delete temp ;
        put(ans.first, ans.second) ;
        return ans.second ;
    }
    
    void put(int key, int value) {

        if(m.find(key) != m.end()){
            Node* temp = m[key] ;
            if(temp == head){
                temp -> nodeVal.second = value ;
                return ;
            }

            if(temp == tail){ 
                tail = temp -> prev ;
                if(tail != NULL && tail -> next != NULL)
                    tail -> next = NULL ;
                m.erase(key) ;
                delete temp ;
            }else{ 
                if(temp != NULL && temp -> prev != NULL && temp -> next != NULL){
                    temp -> prev -> next = temp -> next ;
                    temp -> next -> prev = temp -> prev ;
                }
                m.erase(key) ;
                delete temp ;
            }
        }
        
        // check the size of the map and delete the Least Recently Used (LRU) cache.
        if(m.size() >= size){
            //cout<<"entered & key -> "<<key <<endl; 
            Node* temp = tail ;
            if(head == tail){ // Only one value present in LRU cache
                head = tail = NULL ;
            }else{ // more than one values pressent
                if(tail != NULL){
                    tail = temp -> prev ;
                    tail -> next = NULL ;
                }
            }

            // erase this data from map
            if(temp != NULL)
                m.erase(temp -> nodeVal.first) ;
            delete temp ;
        }

        // insert new entry
        Node* add = new Node({key, value}) ;
        if(head == NULL){
            head = tail = add ;
        }else{
            add -> next = head ;
            head -> prev = add ;
            head = add ;
        }
        // print(head) ;
        m[key] = add ;

        //print(head) ;
    }
};
