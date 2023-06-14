// GFG -> Game with String
https://practice.geeksforgeeks.org/problems/game-with-string4100/1


// T.C. = O(N)
// S.C. = O(26)
class Solution{
public:
    int minValue(string s, int k){
        
        int n = s.length() ;
        unordered_map<char, int> frequencyCount ;
        priority_queue<int> pq ;
        int sum = 0 ;
        
        // step -> 1: count the frequency of all the characters
        for(int i=0 ; i<n ; i++){
            frequencyCount[s[i]]++ ;
        }
        
        // step -> 2: insert frequency in MAX heap
        for(auto it: frequencyCount){
            pq.push(it.second) ;
        }
        
        // step -> 3: uapdte the frequency when we remove k characters from string
        for(int i=1 ; i<=k ; i++){
            int freq = pq.top() ;
            pq.pop() ;
            freq-- ;
            pq.push(freq) ;
        }
        
        // step -> 4: sum of the frequency squre
        while(!pq.empty()){
            int element = pq.top() ;
            pq.pop() ;
            sum += element*element ;
        }
        
        return sum ;
    }
};