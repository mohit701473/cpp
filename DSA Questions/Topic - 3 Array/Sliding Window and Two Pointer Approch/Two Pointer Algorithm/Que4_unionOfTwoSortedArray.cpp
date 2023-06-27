// GFG -> https://practice.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1



// Approch -> 1: using map
// T.C. = O((n+m)log(n+m))
// S.C. = O(n+m)
class Solution{
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> ans ;
        map<int, bool> mp ;
        
        for(int i=0 ; i<n ; i++)
            mp[arr1[i]] = true ;
            
        for(int i=0 ; i<m ; i++)
            mp[arr2[i]] = true ;
            
        for(auto it: mp)
            ans.push_back(it.first) ;
            
        return ans ;
    }
};



// Approch -> 2: using hash map
// T.C. = O(n+m)
// S.C. = O(n+m)
class Solution{
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> ans ;
        unordered_map<int, bool> ump ;
        int i=0, j=0 ;
        
        while(i<n && j<m){
            if(arr1[i] < arr2[j]){
                if(!ump[arr1[i]]){
                    ans.push_back(arr1[i]) ;
                    ump[arr1[i]] = true ;
                }
                i++ ;
            }else{
                if(arr2[j] < arr1[i]){
                    if(!ump[arr2[j]]){
                        ans.push_back(arr2[j]) ;
                        ump[arr2[j]] = true ;
                    }
                    j++ ;
                }
                
                else{
                    if(!ump[arr1[i]]){
                        ans.push_back(arr1[i]) ;
                        ump[arr1[i]] = true ;
                    }
                    i++ ;
                    j++ ;
                }
            }
        }
        
        while(i<n){
            if(!ump[arr1[i]]){
                ans.push_back(arr1[i]) ;
                ump[arr1[i]] = true ;
            }
            i++ ;
        }
        
        
        while(j<m){
            if(!ump[arr2[j]]){
                ans.push_back(arr2[j]) ;
                ump[arr2[j]] = true ;
            }
            j++ ;
        }
        return ans ;
    }
};




// Approch -> 3 : Two Pointer Approch
// T.C. = O(n+m)
// S.C. = O(1) or O(n+m) bcz ans array 
class Solution{
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        
        vector<int> unionn;
        int i = 0, j = 0;
        while(i < n && j < m){
            if(arr1[i] < arr2[j]){
                unionn.push_back(arr1[i++]);
                while(i < n && arr1[i] == arr1[i-1]) i++;
            }
            else if(arr2[j] < arr1[i]){
                unionn.push_back(arr2[j++]);
                while(j < m && arr2[j] == arr2[j-1]) j++;
            }
            else{
                unionn.push_back(arr1[i++]);
                j++;
                while(i < n && arr1[i] == arr1[i-1]) i++;
                while(j < m && arr2[j] == arr2[j-1]) j++;
            }
        }
       
        while(i < n){
            unionn.push_back(arr1[i++]);
            while(i < n && arr1[i] == arr1[i-1]) i++;
        }
       
        while(j < m){
            unionn.push_back(arr2[j++]);
            while(j < m && arr2[j] == arr2[j-1]) j++;
        }
       
        return (unionn);
    }
};