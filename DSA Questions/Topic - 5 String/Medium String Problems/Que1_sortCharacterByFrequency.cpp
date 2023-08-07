// LeetCode -> 451. Sort Characters By Frequency
https://leetcode.com/problems/sort-characters-by-frequency/description/



// Approch -> 1: Heap(Priority Queue)
/*
Approch -> Create a map and store the frequency of the characters and insert the nodes of teh map into Max Heap
           and insertion is done on the basis of the frequency of the charactres
*/
// T.C. = O(Nlog(N))
// S.C. = O(N)

class Solution {
public:
    string frequencySort(string s) {
        int n = s.size() ;
        string ans = "" ;
        unordered_map<char, int> frequecnyCount ;
        for(int i=0 ; i<n ; i++) frequecnyCount[s[i]]++ ;

        priority_queue<pair<int, char> > pq ;
        for(auto it: frequecnyCount) pq.push({it.second, it.first}) ;

        while(!pq.empty()){
            int len = pq.top().first ;
            char ch = pq.top().second ;
            pq.pop() ;
            while(len--) ans += ch ;
        }

        return ans ;
    }
};





// Approch -> Hashing
// T.C. = O(N + 52^2)
// S.C. = O(2N + 52)
class Solution {
public:
    string frequencySort(string s) {
        int n = s.size() ;
        string ans = "" ;
        unordered_map<char, int> frequecnyCount ;
        for(int i=0 ; i<n ; i++) frequecnyCount[s[i]]++ ;

        for(int i=0 ; i<frequecnyCount.size() ; i++){
            pair<char, int> maxFreq ;
            maxFreq.second = 0 ;
            for(auto it: frequecnyCount){
                if(it.second > maxFreq.second){
                    maxFreq = it ;
                }
            }
            frequecnyCount[maxFreq.first] = -1 ;
            string temp(maxFreq.second, maxFreq.first) ;
            ans += temp ;
        }

        return ans ;
    }
};