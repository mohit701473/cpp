// LeetCode -> 151. Reverse Words in a String
https://leetcode.com/problems/reverse-words-in-a-string/description/


// Approch -> 1: String + Stack
// T.C. = O(2N) 
// S.C. = O(2n) 
class Solution {

    void inseretAllWordIntoStack(string s, stack<string> &st){
        string tempWord = "" ;
        int i = 0 ;
        while(i<s.size()){
            if(s[i] == ' '){
                while(i<s.size() && s[i] == ' ') {
                    i++ ;
                }
                if(tempWord != ""){
                    st.push(tempWord) ;
                    tempWord = "" ;
                }
                if(i>=s.size()) break ;
            }
            tempWord += s[i] ;
            i++ ;
        }
        if(tempWord != ""){
            st.push(tempWord) ;
        }
    }

    void reverseAllWords(stack<string> &st, string &ans){
        while(st.size() > 1){
            ans += st.top() ;
            st.pop() ;
            ans += " " ;
        }
        ans += st.top() ;
        st.pop() ;
    }

public:
    string reverseWords(string s) {
        string ans = "" ;
        stack<string> st ;
        inseretAllWordIntoStack(s, st) ;
        reverseAllWords(st, ans) ;
        return ans ;
    }
};



// Approch -> 1: String
// T.C. = O(N) 
// S.C. = O(N) 
class Solution {
public:
    string reverseWords(string s) {

        string ans = "" ;
        int i=0, n=s.size() ;
        while(i<n){
            string temp = "" ;

            while(s[i] == ' ' && i<n) i++ ;

            while(s[i] != ' ' && i<n) temp += s[i++] ;

            if(temp != ""){
                if(ans == "") ans = temp ;
                else ans = temp + " " + ans ;
            }
        }
        return ans ;
    }
};