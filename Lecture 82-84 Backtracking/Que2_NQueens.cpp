#include <bits/stdc++.h> 

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n){
        
        vector<int> temp ;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                temp.push_back(board[i][j]) ;
            }
            
            ans.push_back(temp) ;
        }
    }
    
    bool isSafe(int row, int col, vector<vector<int>> &board, int n){
        int x = row ;
        int y = col ;
        
        // for safe placing check three given condition
        
        // 1st -> check for same row
        while(y >= 0){
            if(board[x][y] == 1)
                return false ;
                
            y-- ;
        }
        
        // 2nd -> check for same column
        // There is no need to check for same column bcz in our code we are placing only one queen in a column 
        
        // 3rd -> check for diagonal
        x = row ;
        y = col ;
        while(x>=0 && y>=0){
            if(board[x][y] == 1)
                return false ;
                
            y-- ;
            x-- ;
        }
        
        
        x = row ;
        y = col ;
        while(x<n && y>=0){
            if(board[x][y] == 1)
                return false ;
                
            y-- ;
            x++ ;
        }
        
        
        return true ;
    }

    void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n){
        
        // base case
        if(col == n){
            addSolution(ans, board, n) ;
            return ;
        }
        
        // Solve one case and other is handleed by recursion
        for(int row=0 ; row<n ; row++){
            
            if(isSafe(row, col, board, n)) {  // ky yha es row, es column & is borad pr queen rkhan asafe h
                // if safe then put queen 
                board[row][col] = 1 ;
                solve(col+1, ans, board, n) ;
                
                // backtrack krte huve queen ko vaps hta do
                board[row][col] = 0 ;
            }
        }
    }

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board(n, vector<int> (n,0)) ;
        
        vector<vector<int>> ans ;
        
        solve(0, ans, board, n) ;
        
        return ans ;
	
}