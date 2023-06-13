// Leetcode -> 150. Evaluate Reverse Polish Notation
https://leetcode.com/problems/evaluate-reverse-polish-notation/description/



// T.C. =  O(N)
// S.C. = O(N)
class Solution {

    int getResult(stack<string> &st, string &str){
        int num1 = stoi(st.top()) ;
        st.pop() ;
        int num2 = stoi(st.top()) ;
        st.pop() ;
        
        if(str == "+")  return num1 + num2 ;
        if(str == "-")  return num2 - num1 ;
        if(str == "*")  return num1 * num2 ;
        return num2 / num1 ;
    }

public:
    int evalRPN(vector<string>& tokens) {
        
        int n = tokens.size() ;
        stack<string> st ;

        for(int i=0 ; i<n ; i++){
            string str = tokens[i] ;

            if(str=="+" || str=="-" || str=="*" || str=="/"){
                int ans = getResult(st, str) ;
                st.push(to_string(ans)) ;
            }else{
                st.push(str) ;
            }
        }

        return stoi(st.top()) ;
    }
};





// GFG -> Evaluation of Postfix Expression
https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1


// T.C. =  O(N)
// S.C. = O(N)
class Solution
{
    int getResult(stack<int> &st, char ch){
        int num1 = st.top() ;
        st.pop() ;
        int num2 = st.top() ;
        st.pop() ;
        
        if(ch == '+')  return num1 + num2 ;
        if(ch == '-')  return num2 - num1 ;
        if(ch == '*')  return num1 * num2 ;
        if(ch == '/')  return num2 / num1 ;
    }
    public:
    
    int evaluatePostfix(string S)
    {
        int n = S.length() ;
        stack<int> st ;
        
        for(int i=0 ; i<n ; i++){
            char ch = S[i] ;
            
            if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
                int ans = getResult(st, ch) ;
                st.push(ans) ;
            }else{
                st.push(int(ch) - 48) ;
            }
        }
        
        return st.top() ;
    }
};

