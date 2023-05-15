//Longest Common Prefix in an Array

// Approch -1
// T.C. = O(N*M)  N -> total no. of strings & M -> length of 1st string 
// S.C. = O(1) if don't include ans string bcz ans string we have to return so this space is recuired 
class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        string ans ;
        
        for(int i=0 ; i<arr[0].size() ; i++){
            char ch = arr[0][i] ;
            bool flag = true ;
            for(int j=0 ; j<N ; j++){
                
                if(ch != arr[j][i]){
                    flag = false ;
                    break ;
                }
            }
            
            if(flag){
                ans.push_back(arr[0][i]) ;
            }
            else break ;
        }
        
        if(ans.empty()) return "-1" ;
        return ans ;
    }
        
};


// Approch -2 using tries
// T.C. = O(N*M)  N -> total no. of strings & M -> length of 1st string 
// S.C. = O(N*M)
class Solution{
  public:
  
    class TrieNode{
        public:
        char data ;
        int childCount ;
        TrieNode* children[26] ;
        bool isTerminal ;
        
        TrieNode(char ch){
            data = ch ;
            childCount = 0 ;
            
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
        
        void insertUtil(TrieNode* root, string word){
            if(word.size() == 0){
                root -> isTerminal = true ;
                return ;
            }
            
            int index = word[0] - 'a' ;
            TrieNode* child ;
            
            if(root -> children[index] != NULL){
                child = root -> children[index] ;
            }
            
            else{
                root -> childCount++ ;
                child = new TrieNode(word[0]) ;
                root -> children[index] = child ;
            }
            
            insertUtil(child, word.substr(1) ) ;
        }
        
        void insertWord(string word){
            insertUtil(root, word) ;
        }
        
        string lcs(string word){
            string ans ;
            TrieNode* temp = root ;
            for(int i=0 ; i<word.size() ; i++){
                
                char ch = word[i] ;
                
                if(temp -> childCount == 1){
                    ans.push_back(ch) ;
                    int index = word[i] - 'a' ;
                    temp = temp -> children[index] ;
                }
                
                else return ans ;
                
                if(temp -> isTerminal) return ans ;
            }
            
            return ans ;
        }
    };
    
    string longestCommonPrefix (string arr[], int N)
    {
        string ans ;
        
        Trie *t = new Trie() ;
        for(int i=0 ; i<N ; i++){
            t -> insertWord(arr[i]) ;
        }
    
        ans = t -> lcs(arr[0]) ;
        
        if(ans.empty()) return "-1" ;
        
        return ans ;
        
    }
};