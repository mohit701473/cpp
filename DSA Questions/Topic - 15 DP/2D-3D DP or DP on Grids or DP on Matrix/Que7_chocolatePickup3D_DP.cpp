// Coding Ninja -> Chocolate Pickup
https://www.codingninjas.com/studio/problems/chocolate-pickup_3125885



// Approch -> 1: Recursive Approch
// T.C. = O(3^n * 3^n)
// S.C. = O(n)
int solveRecursive(int i, int j1, int j2, vector<vector<int>> &grid){
    // step -> 1: Base cases
    // 1st Base Case out of boundary of grid
    int n = grid.size() , m = grid[0].size() ;
    if(i >= n || j1 < 0 || j1 >= m || j2 < 0 || j2 >= m){
        return INT_MIN ;
    }

    // 2nd base case if reachs at destination
    if(i == n-1){
        // Alice and Bob at the same column
        if(j1 == j2){
            return grid[i][j1] ;
        }
        // Alice and Bob are in different column
        else return grid[i][j1] + grid[i][j2] ;
    }


    // Step -> 2: Explore all the paths
    int maxi = INT_MIN ;
    for(int dj1 = -1 ; dj1 <= 1 ; dj1++){
        for(int dj2 = -1 ; dj2 <= 1 ; dj2++){

            int currStateVal = 0 ;

            // if Allice and Bob are in same column
            if(j1 == j2){
                currStateVal = grid[i][j1] ;
            }
            // Allice and Bob are in different column
            else{
                currStateVal = grid[i][j1] + grid[i][j2] ;
            } 

            
            int stateChange = solveRecursive(i+1, j1+dj1 , j2+dj2 , grid) ;

            int result = currStateVal + stateChange ;
            
            maxi = max(maxi, result) ;
        } 
    }

    return maxi ;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {

    return solveRecursive(0, 0, c-1, grid) ;
}




// Approch -> 2: Memoization + Recursion
// T.C. = O(N*M*M)
// S.C. = O(N*M*M) + O(N)
int solveMem(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
    // step -> 1: Base cases
    // 1st Base Case out of boundary of grid
    int n = grid.size() , m = grid[0].size() ;
    if(i >= n || j1 < 0 || j1 >= m || j2 < 0 || j2 >= m){
        return INT_MIN ;
    }

    // 2nd base case if reachs at destination
    if(i == n-1){
        // Alice and Bob at the same column
        if(j1 == j2){
            return grid[i][j1] ;
        }
        // Alice and Bob are in different column
        else return grid[i][j1] + grid[i][j2] ;
    }

    // Return the result of subproblem
    if(dp[i][j1][j2] != -1){
        return dp[i][j1][j2] ;
    }


    // Step -> 2: Explore all the paths
    int maxi = INT_MIN ;
    for(int dj1 = -1 ; dj1 <= 1 ; dj1++){
        for(int dj2 = -1 ; dj2 <= 1 ; dj2++){

            int currStateVal = 0 ;

            // if Allice and Bob are in same column
            if(j1 == j2){
                currStateVal = grid[i][j1] ;
            }
            // Allice and Bob are in different column
            else {
                currStateVal = grid[i][j1] + grid[i][j2];
            }

            int stateChange = solveMem(i + 1, j1 + dj1, j2 + dj2, grid, dp);

            int result = currStateVal + stateChange;

            maxi = max(maxi, result);
        }
    }

    // step -> 2: Store the result of subproblem
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {

    // Step -> 1: Declear a DP data structure
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c,-1))) ;

    return solveMem(0, 0, c-1, grid, dp) ;
}





// Approch -> 3: Tabulation
// T.C. = O(N*M*M)
// S.C. = O(N*M*M)
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {

    // Step -> 1: Declear a DP data structure
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,-1))) ;

    // step -> 2: write the all the base cases 
    for(int j1 = 0 ; j1<m ; j1++){
        for(int j2 = 0 ; j2<m ; j2++){

            if(j1 == j2){
                dp[n-1][j1][j2] = grid[n-1][j1] ;
            }

            else{
                dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2] ;
            }
        }
    }

    // step -> 3: Express every state in for loop
    for(int i=n-2 ; i>=0 ; i--){

        for(int j1=0 ; j1<m ; j1++){

            for(int j2=0 ; j2<m ; j2++){

                // copy & paste the recurance from memoization approch
                int maxi = INT_MIN ;
                for(int dj1 = -1 ; dj1 <= 1 ; dj1++){
                    for(int dj2 = -1 ; dj2 <= 1 ; dj2++){

                        int currStateVal = 0 ;

                        // if Allice and Bob are in same column
                        if(j1 == j2){
                            currStateVal = grid[i][j1] ;
                        }
                        // Allice and Bob are in different column
                        else {
                            currStateVal = grid[i][j1] + grid[i][j2];
                        }

                        int stateChange = INT_MIN ;
                        if((j1+dj1 >=0 && j1+dj1 < m) && (j2+dj2 >=0 && j2+dj2 < m)){
                            stateChange = dp[i+1][j1+dj1][j2+dj2] ;
                        }

                        int result = currStateVal + stateChange;

                        maxi = max(maxi, result);
                    }
                }

                dp[i][j1][j2] = maxi ;
            }
        }
    }

    // bcz call for Alice start at (0,0) and Bob start at (0,m-1)
    return dp[0][0][m-1] ;
}






// Approch -> 4: Space optimization
// T.C. = O(N*M*M)
// S.C. = O(2*M*M)
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {

    // Step -> 1: Declear a DP data structure
    vector<vector<int>> front(m, vector<int>(m,-1)) ;
    vector<vector<int>> curr(m, vector<int>(m,-1)) ;

    // step -> 2: write the all the base cases 
    for(int j1 = 0 ; j1<m ; j1++){
        for(int j2 = 0 ; j2<m ; j2++){

            if(j1 == j2){
                front[j1][j2] = grid[n-1][j1] ;
            }

            else{
                front[j1][j2] = grid[n-1][j1] + grid[n-1][j2] ;
            }
        }
    }

    // step -> 3: Express every state in for loop
    for(int i=n-2 ; i>=0 ; i--){

        for(int j1=0 ; j1<m ; j1++){

            for(int j2=0 ; j2<m ; j2++){

                // copy & paste the recurance from memoization approch
                int maxi = INT_MIN ;
                for(int dj1 = -1 ; dj1 <= 1 ; dj1++){
                    for(int dj2 = -1 ; dj2 <= 1 ; dj2++){

                        int currStateVal = 0 ;

                        // if Allice and Bob are in same column
                        if(j1 == j2){
                            currStateVal = grid[i][j1] ;
                        }
                        // Allice and Bob are in different column
                        else {
                            currStateVal = grid[i][j1] + grid[i][j2];
                        }

                        int stateChange = INT_MIN ;
                        if((j1+dj1 >=0 && j1+dj1 < m) && (j2+dj2 >=0 && j2+dj2 < m)){
                            stateChange = front[j1+dj1][j2+dj2] ;
                        }

                        int result = currStateVal + stateChange;

                        maxi = max(maxi, result);
                    }
                }

                curr[j1][j2] = maxi ;
            }
        }
        front = curr ;
    }

    return front[0][m-1] ;
}