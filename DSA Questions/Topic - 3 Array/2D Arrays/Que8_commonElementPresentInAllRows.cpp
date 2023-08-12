// Coding Ninja -> Common Elements Present In All Rows Of Matrix
https://www.codingninjas.com/studio/problems/common-elements-present-in-all-rows-of-a-matrix_1118111


// Approch -> 1: Brute Force Approch
/*
approch -> In first row check every element present in all rows or not
*/
// T.C. = O(N*M*N) + O(N)
// S.C. = O(M)
#include<unordered_map>
bool searchForCommonElement(vector<vector<int>> &mat, int commonEle, int n , int m){
    bool isCommon = true ;
    for(int i=1 ; i<n ; i++){
        bool flag = true ; // initialy we consider that this(commonEle) is not a common element accros all the rows
        for(int j=0 ; j<m ; j++){
            if(mat[i][j] == commonEle){
                flag = false ;
                break ;
            }
        }
        if(flag){
            isCommon = false ;
            break ;
        }
    }

    return isCommon ;
}

vector<int> findCommonElements(vector<vector<int>> &mat)
{
    vector<int> ans ;
    int n = mat.size() , m = mat[0].size() ;
    unordered_map<int , bool> ump ;
    for(int i=0 ; i<m ; i++) ump[mat[0][i]] = true ;

    for(int i=0 ; i<m ; i++){
        int commonEle = mat[0][i] ;
        if(ump[commonEle] && searchForCommonElement(mat, commonEle,n , m)){
            ans.push_back(commonEle) ;
        }
        ump[commonEle] = false ;
    }

    return ans ;
}







// Approch -> 2: unorderd map
/*
The idea is to use maps. We initially insert all elements of the first row in an map. For every other element in 
remaining rows, we check if it is present in the map. If it is present in the map and is not duplicated in 
current row, we increment count of the element in map by 1, else we ignore the element. If the currently 
traversed row is the last row, we print the element if it has appeared m-1 times before. 
*/
// T.C. = O(N*M)
// S.C. = O(M)
#include<unordered_map>
vector<int> findCommonElements(vector<vector<int>> &mat)
{
    vector<int> ans ;
    int n = mat.size() , m = mat[0].size() ;
    unordered_map<int, int> mp;
  
    // initialize 1st row elements with value 1
    for (int j = 0; j < m; j++)
        mp[(mat[0][j])] = 1;

    if(n==1){
        for(int i=0 ; i<m ; i++)
            ans.push_back(mat[0][i]) ;
    }
  
    // traverse the matrix
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // If element is present in the map and
            // is not duplicated in current row.
            if (mp[(mat[i][j])] == i)
            {
               // we increment count of the element
               // in map by 1
                mp[(mat[i][j])] = i + 1;
  
                // If this is last row
                if (i==n-1 && mp[(mat[i][j])]==n){
                    ans.push_back(mat[i][j]);
                    mp[(mat[i][j])] = n+1 ;
                }
            }
        }
    }

    return ans ;
}
