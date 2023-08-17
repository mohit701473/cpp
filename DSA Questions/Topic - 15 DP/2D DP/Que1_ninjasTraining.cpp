// Coding Ninja -> Ninja’s Training
https://www.codingninjas.com/studio/problems/ninja-s-training_3621003



// Approch -> 1: recursive Approch
// T.C. = Exponential -> TLE
// S.C. = O(N)
int solveRecursive(int day, int last_tack, vector<vector<int> > &points){
    // Base case
    if(day == 0){
        int maxi = 0 ;
        for(int i=0 ; i<3 ; i++){
            if(i != last_tack){
                maxi = max(maxi, points[0][i]) ;
            }
        }

        return maxi ;
    }

    int maxiPoints = 0 ;
    for(int i=0 ; i<3 ; i++){
        if(i != last_tack){
            int point = points[day][i] + solveRecursive(day-1, i, points) ;
            maxiPoints = max(maxiPoints, point) ;
        }
    }

    return maxiPoints ;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return solveRecursive(n-1, 3, points) ;
}




// Approch -> 2: Memoization + Recursion
// T.C. = O( (N*4) * 3 )
// S.C. = O(4N) + O(N)
int solveMem(int day, int last_task, vector<vector<int> > &points, vector<vector<int>> &dp){
    // Base case
    if(day == 0){
        int maxi = 0 ;
        for(int i=0 ; i<3 ; i++){
            if(i != last_task){
                maxi = max(maxi, points[0][i]) ;
            }
        }

        return maxi ;
    }
    
    // step -> 3: if this subproblem is previously solved then return directly result 
    if(dp[day][last_task] != -1){
        return dp[day][last_task] ;
    }

    int maxPoints = 0 ;
    for(int i=0 ; i<3 ; i++){
        if(i != last_task){
            int point = points[day][i] + solveRecursive(day-1, i, points, dp) ;
            maxPoints = max(maxPoints, point) ;
        }
    }

    // step -> 2: store the result of subproblem into DP 
    // dp[day][last_task] => dp[1][0] eska mtlb hai ki jub m day 2 pr 0-th task perform krta hu to eski vajah se mai day 0 se day 1 
    // tk kitne maximum points earn kr paya mai
    // dp[2][2] -> eska matlb hai ki jub mai day 3rd par 2nd task perform krta hu to eski vajah se mai day 2nd se lekar 
    // day 0 tk kitne maximum poits earn kr paya us value ko mene dp[2][2] me store kiya
    dp[day][last_task] = maxPoints ;
    return dp[day][last_task] ;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // step -> 1: Declear a DP data structure
    vector<vector<int> > dp(n, vector<int>(4,-1)) ;
    return solveMem(n-1, 3, points, dp) ;
}




// Approch -> 3: Tabulation method
// T.C. = O(12N)
// S.C. = O(4N)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // step -> 1: Declear a DP data structure
    vector<vector<int> > dp(n, vector<int>(4,-1)) ;

    // step -> 2: base cases analyses
    dp[0][0] = max(points[0][1] , points[0][2]) ;
    dp[0][1] = max(points[0][0] , points[0][2]) ;
    dp[0][2] = max(points[0][0] , points[0][1]) ;
    dp[0][3] = max(points[0][0] , max(points[0][1], points[0][2])) ;

    for(int day=1 ; day<n ; day++){
        for(int last_task = 0 ; last_task < 4 ; last_task++){
            dp[day][last_task] = 0 ;

            for(int curr_task = 0 ; curr_task < 3 ; curr_task++){
                if(curr_task != last_task){
                    int point = points[day][curr_task] + dp[day-1][curr_task] ;
                    dp[day][last_task] = max(dp[day][last_task] , point) ;
                }
            }
        }
    }

    return dp[n-1][3] ;
}




// Approch -> 4: Space Optimization
// T.C. = O(12N)
// S.C. = O(1)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4,0) ;
    
    prev[0] = max(points[0][1] , points[0][2]) ;
    prev[1] = max(points[0][0] , points[0][2]) ;
    prev[2] = max(points[0][0] , points[0][1]) ;
    prev[3] = max(points[0][0] , max(points[0][1], points[0][2])) ;

    for(int day=1 ; day<n ; day++){
        vector<int> temp(4,0) ;
        for(int last_task = 0 ; last_task < 4 ; last_task++){
            temp[last_task] = 0 ;

            for(int curr_task = 0 ; curr_task < 3 ; curr_task++){
                if(curr_task != last_task){
                    int point = points[day][curr_task] + prev[curr_task] ;
                    temp[last_task] = max(temp[last_task], point) ;
                }
            }
        }
        prev = temp ;
    }

    return prev[3] ;
}