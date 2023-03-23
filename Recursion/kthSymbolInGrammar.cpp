class Solution {
public:

    void replace(vector<vector<string>> &str, vector<string> rowStr){
        int i=0 ;
        int size = rowStr.size() ;
        vector<string> temp ;
        while(i<size) {
            if(rowStr[i] == "0") {
                temp.push_back("01") ;
            }
            
            else{
                temp.push_back("10") ;
            }
        }
        str.push_back(temp) ;
        return ;
    }

    void solve(vector<vector<string>> &str, int n){
        vector<string> temp ;
        if(n==0) {
            temp.push_back("0") ;
            str.push_back(temp) ;
            return ;
        }
        
        solve(str, n-1) ;
        replace(str, str[n-1]) ;
        return ;
    }

    int kthGrammar(int n, int k) {
        vector<vector<string>> str ;
        solve(str, n) ;

        int ans = 1 ;
        if(str[n-1][k-1] == "0") 
            ans = 0 ;

        return ans ;
    }
};