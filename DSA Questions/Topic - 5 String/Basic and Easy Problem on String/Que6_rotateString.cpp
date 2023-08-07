// LeetCode -> 796. Rotate String
https://leetcode.com/problems/rotate-string/description/


// Approch -> 1: Rotate string one by one
// T.C. = O(N^2)
// S.C. = O(1)
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false ;
        if(s == goal) return true ;
        int n = s.size() ;
        for(int i=0 ; i<n ; i++){
            char last = s[n-1], prev = s[0] ;
            s[n-1] = s[0] ;
            for(int i=n-2 ; i>=0 ; i--){
                prev = s[i] ;
                s[i] = last ;
                last = prev ;
            }

            if(s == goal) return true ;
        }

        return false ;
    }
};



// Approch -> 2: string function sustr()
// T.C. = O(N^2)
// S.C. = O(1)
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false ;
        int n = s.size() ;
        while(n--){
            if(s == goal) return true ;
            s = s.substr(1) + s[0] ;
        }
        return false ;
    }
};



// Approch -> 3: using queue
// T.C. = O(N^2)
// S.C. = O(2N)
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false ;

        int n = s.size() ;
        queue<char> q1, q2 ;
        for(int i=0 ; i<n ; i++){
            q1.push(s[i]) ;
            q2.push(goal[i]) ;
        }

        while(n--){
            if(q1 == q2) return true ;
            char ch = q1.front() ;
            q1.pop() ;
            q1.push(ch) ;
        }

        return false ;
    }
};