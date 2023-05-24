// Que. => 347. Top K Frequent Elements
/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
*/

https://leetcode.com/problems/top-k-frequent-elements/



//------------------------------------------------------------   Solution    -----------------------------------------------------------------------


// Approch - 1 
// assume size of given vector nums is => N
// T.C. = O(k*n) but in worst case T.C. = O(N^2)  bcz in worst case all element have distinct value & k = N
// S.C. = O(N) in worst case 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int , int> m ;

        // T.C. = O(nlog(n))  =>  this for loop  
        // take n = size of map
        for(int i=0 ; i<nums.size() ; i++)  
            m[nums[i]]++ ;

        vector<int> ans ; 


        // T.C. = O(k*(n + log(n)))  => this is for complete while loop
        while(k > 0){
            int maxFreq = 0 ;
            int element ;
            
            // T.C. = O(n)
            for(auto it: m){
                if(it.second > maxFreq){
                    element = it.first ;
                    maxFreq = it.second ;
                }
            }

            ans.push_back(element) ; 
            m.erase(element) ;  // T.C. = O(log(n))
            k-- ;
        }

        return ans ;
    }
};




// Approch - 2 Using Unordered Map and Priority Queue Min Heap
// Assume size of given vector nums => N
// T.C. = O(Nlog(n))   in the worst case n(no. of element in pq) => N and k => N  so  T.C. = O(N) + O(Nlog(N)) + O(Nlog(N)) + O(Nlog(N))  => O(Nlog(N))
// S.C. = (N)  in the worst case 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> ans ;

        unordered_map<int, int> m ; // unordered_map<val, freq> m

        // T.C. = O(N) 
        for(int i=0 ; i<nums.size() ; i++)
            m[nums[i]]++ ;


        priority_queue<pair<int, int> , vector<pair<int, int> > , greater<pair<int, int> > > pq ;

        // insert first k element from map to priority queue
        // T.C. = O(k(log(n)))  n => elements in priority queue
        for(int i=0 ; i<k ; i++){
            auto it = m.begin() ;
            pair<int, int> p = make_pair(it -> second, it -> first) ;
            pq.push(p) ;  // T.C. = O(log(n))
            m.erase(it) ;
        }


        // T.C. = O(N(log(n)))  n => elements in priority queue
        while(!m.empty()){
            auto it = m.begin() ;

            if(it -> second > pq.top().first){
                pq.pop() ; // T.C. = O(log(n))
                pair<int, int> p = make_pair(it -> second, it -> first) ;
                pq.push(p) ;
            }

            m.erase(it) ;
        }

        // T.C. = O(N(log(n)))  n => elements in priority queue
        while(!pq.empty()){
            pair<int, int> p = pq.top() ;
            pq.pop() ;  // T.C. = O(log(n))
            ans.push_back(p.second) ;
        }


        return ans ;
    }
};



// Approch - 3 Unordered Map + Priority Queue Max Heap
// T.C. = O(klog(N))  but in the worst case k = N then T.C. = O(Nlog(N))
// S.C. = O(N)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n=nums.size();
        unordered_map<int,int>mp;
        vector<int> Res;
       
        // T.C. = O(N)
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int,int>> m;
        // T.C. = O(N)
        for( auto i : mp)
        {
            m.push(make_pair( i.second, i.first));
        }
        
        // T.C. = O(klog(N))
        for( int i =0;i<k ; i++)
        {
            Res.push_back( m.top().second);
            m.pop();
        }
      
        return Res;
    }
};