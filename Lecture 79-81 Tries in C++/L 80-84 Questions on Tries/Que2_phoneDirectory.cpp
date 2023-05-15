// Implement a phone directory

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
            int index = word[0] - 'a' ;
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
        
        

        void printSuggestions(TrieNode* curr, vector<string> &temp, string &prefix){
            
            if(curr -> isTerminal)
                temp.push_back(prefix) ;

            for(char ch='a' ; ch <= 'z' ; ch++){
                
                TrieNode* next = curr -> children[ch - 'a'] ;

                if(next != NULL){
                    prefix.push_back(ch) ;
                    printSuggestions(next, temp, prefix) ;
                    prefix.pop_back() ;
                }
            }
        }
        
        vector<vector<string>> getSuggestions(string str){
            
            TrieNode* prev = root ;
            string prefix = "" ;
            vector<vector<string>> output ;
            
            for(int i=0 ; i<str.size() ; i++){
                
                char lastch = str[i] ;
                
                prefix.push_back(lastch) ;

                TrieNode* curr = prev -> children[lastch - 'a'] ;  // check lastch is present in Trie

                if(curr == NULL) // not present
                    break ;
                    
                
                // present     
                vector<string> temp ;
                
                printSuggestions(curr, temp, prefix) ;
                output.push_back(temp) ;
                temp.clear() ;
                
                prev = curr ;
            }

            return output ;
            
        }

    };

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie* t = new Trie() ;
        
        // insert all the contact list into Trie
        for(int i=0 ; i<contactList.size() ; i++)
            t -> insertWord(contactList[i]) ;
            
        return t -> getSuggestions(queryStr) ;
}





// not in lexicographical increasing order.
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string> > ans ;
        
        vector<string> temp ;
        
        for(int i=0 ; i<n ; i++){
            if(s[0] == contact[i][0])
                temp.push_back(contact[i]) ;
        }
        
        ans.push_back(temp) ;
        
        int i=1 ;
        while(i < s.size()){
            vector<string> temp1 ;
            bool flag = false ;
            
            for(int j=0 ; j<ans[i-1].size() ; j++){
                string str = ans[i-1][j] ;
                
                if(i < str.size() && s[i] == str[i]){
                    temp1.push_back(str) ;
                    flag = true ;
                }
            }
            
            if(flag){
                ans.push_back(temp1) ;
                i++ ;
            }
            
            else break ;
        }
        
        if(i < s.size()){
            for(i ; i<s.size() ; i++){
                string ch = "0" ;
                vector<string> str ;
                str.push_back(ch) ;
                ans.push_back(str) ;
            }
        }
        
        return ans ;
        
    }
};