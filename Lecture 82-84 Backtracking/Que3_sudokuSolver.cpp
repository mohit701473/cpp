

class Solution 
{
    public:
    
    bool isSafe(int row, int col, int board[][9], int val){

        for(int i=0 ; i<9; i++){
    
            // check for same row
            if(board[row][i] == val)
                return  false ;
    
            // check for column
            if(board[i][col] == val)
                return false ;
    
            // check in 3*3 matrix
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val)
                return false ;
        }

        return true ;
    }
     
    bool SolveSudoku(int grid[N][N])  
    { 
        for(int row=0 ; row<N ; row++){
            for(int col=0 ; col<N ; col++){
                
                // empty cell 
                if(grid[row][col] == 0){
    
                    for(int val=1 ; val<=9 ; val++){
    
                        if(isSafe(row, col, grid, val)){
                            grid[row][col] = val ;
    
                            // recursive call
                            bool aageSolutionPosible = SolveSudoku(grid) ;
    
                            if(aageSolutionPosible){
                                return true ;
                            }
    
                            else{
                                // backtracking
                                grid[row][col] = 0 ;
                            }
                        }
                    }
    
                    return false ;
                }
            }
        }
    
        return true ;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0 ; i<N ; i++){
            for(int j=0 ; j<N ; j++){
                cout<<grid[i][j] << " ";
            }
        }
    }
};