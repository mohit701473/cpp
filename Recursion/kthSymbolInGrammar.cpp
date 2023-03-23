class Solution {
public:
    void print(vector<vector<char>> str){
        for(auto it: str){
            for(auto it1: it)
                cout<<it1 ;
        }cout<<endl;
    }

    void replace(vector<vector<char>> &str, vector<char> rowStr){
        int i=0 ;
        int size = rowStr.size() ;
        vector<char> temp ;
        //cout<<"rowStr: ";
        while(i<size) {
            //cout<<rowStr[i] ;
            if(rowStr[i] == '0') {
                temp.push_back('0') ;
                temp.push_back('1') ;
            }
            
            else{
                temp.push_back('1') ;
                temp.push_back('0') ;
            }
            i++ ;
        }
        str.push_back(temp) ;
        return ;
    }

    void solve(vector<vector<char>> &str, int n){
        vector<char> temp ;
        if(n==0) {
            temp.push_back('0') ;
            str.push_back(temp) ;
            return ;
        }
        
        solve(str, n-1) ;
        replace(str, str[n-1]) ;
        return ;
    }

    int kthGrammar(int n, int k) {
        if(k==1)
            return 0 ;
        vector<vector<char>> str ;
        solve(str, n) ;
        // cout<<"final str: "<<endl;
        // print(str) ;
        //cout<<endl;
        int ans = 1 ;
        if(str[n-1][k-1] == '0') 
            ans = 0 ;

        return ans ;
    }
};