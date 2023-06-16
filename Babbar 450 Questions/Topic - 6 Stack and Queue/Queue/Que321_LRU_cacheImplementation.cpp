// LeetCode -> 146. LRU Cache
https://leetcode.com/problems/lru-cache/description/



// Optimised Code
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

    // update the cache when get(key) called or put(key, value) called for already exist key
    void delteKeyFromCache(int key, int value){
        Node* temp = m[key] ;

        // if key is at the tail i.e temp == tail
        if(temp == tail){ 
            tail = temp -> prev ;
            tail -> next = NULL ;
        }
        // else key present in any position in doubley list except head & tail
        else{ 
            temp -> prev -> next = temp -> next ;
            temp -> next -> prev = temp -> prev ;
        }

        m.erase(key) ;
        delete temp ;
    }


    // delet Lest Recenty Used(LRU) Cache i.e. delete last Node form doubley list
    void deleteLestRecentlyUsedKey(){
        Node* temp = tail ;

        // Only one value present in LRU cache
        if(head == tail){
            head = tail = NULL ;
        }
        else{
            tail = temp -> prev ;
            tail -> next = NULL ;
        }

        m.erase(temp -> nodeVal.first) ;
        delete temp ;
    }

    // Insert new entry in cache
    void addKeyIntoCache(int key, int value){
        Node* add = new Node({key, value}) ;
        if(head == NULL){
            head = tail = add ;
        }
        else{
            add -> next = head ;
            head -> prev = add ;
            head = add ;
        }

        m[key] = add ;
    }

public:
    LRUCache(int capacity) {
        size = capacity ;
        head = tail = NULL ;
    }
    
    int get(int key) {

        // step -> 1: if key not present in the cache
        if(m.find(key) == m.end())
            return -1 ;

        // step -> 2: store the ans
        Node* temp = m[key] ;
        pair<int, int> ans = temp -> nodeVal ;

        // step -> 3: update the cache
        if(temp != head){
            delteKeyFromCache(ans.first, ans.second) ;
            put(ans.first, ans.second) ;
        }

        return ans.second ;
    }
    
    void put(int key, int value) {
        
        // step -> 1: if key present in the map i.e key already exist in the LRU cache
        if(m.find(key) != m.end()){
            if(m[key] == head){
                m[key] -> nodeVal.second = value ;
                return ;
            }
            delteKeyFromCache(key, value) ;
        }
        
        // step -> 2: check the size of the cache(map) and delete the Least Recently Used(LRU) cache.
        if(m.size() >= size){
            deleteLestRecentlyUsedKey() ; 
        }

        // step -> 3: insert new pair into cache
        addKeyIntoCache(key, value) ;
    }
};





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
