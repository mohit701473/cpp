#include<iostream>
using namespace std ;

class TrieNode{
    public:
    char data ;
    TrieNode* children[26] ;
    bool isTerminal ;

    // constructor
    TrieNode(char ch){
        data = ch ;

        for(int i=0 ; i<26 ; i++)
            children[i] = NULL ;

        isTerminal = false ;
    }
};

class Trie{
    public:
    TrieNode* root ;

    Trie(){
        root = new TrieNode('\0') ;

    }

// Insertion function to insert a word into trie
    void insertUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            root -> isTerminal = true ;
            return ;
        }

        // Assumption -> Word contain only capital letters
        int index = word[0] - 'A' ;
        TrieNode* child ;
        // if character is present in trie
        if(root -> children[index] != NULL){
            child = root -> children[index] ;
        }

        else {  // absent
            child = new TrieNode(word[0]) ;
            root -> children[index] = child ;
        }

        // recursive call
        insertUtil(child, word.substr(1)) ;
    }

    void insertWord(string word){
        insertUtil(root, word) ;
    }


// Search Function to search word in Trie

    bool searchUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            return root -> isTerminal ;
        }

        int index = word[0] - 'A' ;
        TrieNode* child ; 

        // present
        if(root -> children[index] != NULL){
            child = root -> children[index] ;
        }

        else{ // absent
            return false ;
        }

        // recursive call
        return searchUtil(child, word.substr(1)) ;
    }

    bool searchWord(string word){
        return searchUtil(root, word) ;
    }


// Remove word from Trie

    void removeUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root -> isTerminal = false ;
            return ;
        }
        int index = word[0] - 'A' ;
        TrieNode* child = root -> children[index] ;

        removeUtil(child, word.substr(1)) ;
    }

    void removeWord(string word){
        // step -> 1 search word
        bool findWord = searchWord(word) ;
        if(findWord){
            removeUtil(root, word) ;
        }

        else{
            cout<< "Word is Not present"<<endl ;
            return ;
        }
    }
};


int main(){
    Trie* t = new Trie() ;

    t->insertWord("ABCD") ;
    t->insertWord("PQR") ;
    t->insertWord("XYZ") ;
    t->insertWord("RST") ;

    cout<<"Present or Not -> "<< t->searchWord("ABCD") << endl ;
    cout<<"Present or Not -> "<< t->searchWord("ABC") << endl ;

    t -> removeWord("ABCD") ;
    cout<<"Present or Not -> "<< t->searchWord("ABCD") << endl ;

}


// gfg Trie Insertion and search
// Itrative insertion & Searching

/*
    void insert(struct TrieNode *root, string word)
{
    TrieNode *node = root;
    for(int i = 0; i < word.size(); i++) {
        int ind = word[i] - 'a';
        
        if(!node->children[ind])  // if null
            node->children[ind] = getNode();
        
        node = node->children[ind];
    }
    node->isLeaf = true;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    TrieNode *node = root;
    for(int i = 0; i < key.size(); i++) {
        if(!node->children[key[i] - 'a']) // if null
            return false;
        else
            node = node->children[key[i] - 'a'];
    }
    return node->isLeaf;
}
*/