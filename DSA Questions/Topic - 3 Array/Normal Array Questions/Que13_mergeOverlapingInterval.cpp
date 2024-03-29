


// Approch -> 1: Brute Force Approch
// Time Complexity: O(N*logN) + O(2*N), where N = the size of the given array.
// Reason: Sorting the given array takes  O(N*logN) time complexity. Now, after that, we are using 2 loops i and j. 
// But while using loop i, we skip all the intervals that are merged with loop j. So, we can conclude that every 
// interval is roughly visited twice(roughly, once for checking or skipping and once for merging). So, the time 
// complexity will be 2*N instead of N2.

// Space Complexity: O(N), as we are using an answer list to store the merged intervals. Except for the answer array, 
// we are not using any extra space.
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size() ;
        if(n == 1) return intervals ;
        
        vector<vector<int> > ans ;
        sort(intervals.begin(), intervals.end()) ;
        
        for (int i = 0; i < n; i++) { // select an interval:
            int start = intervals[i][0];
            int end = intervals[i][1];

            //Skip all the merged intervals:
            if (!ans.empty() && end <= ans.back()[1]) {
                continue;
            }

            //check the rest of the intervals:
            for (int j = i + 1; j < n; j++) {
                if (intervals[j][0] <= end) {
                    end = max(end, intervals[j][1]);
                }
                else {
                    break;
                }
        }
        ans.push_back({start, end});
    }
        
        return ans ;
    }
};




// Approch -> 2: Optimal Approch
// Time Complexity: O(N*logN) + O(N), where N = the size of the given array.
// Reason: Sorting the given array takes  O(N*logN) time complexity. Now, after that, we are just using a single loop 
// that runs for N times. So, the time complexity will be O(N).

// Space Complexity: O(N), as we are using an answer list to store the merged intervals. Except for the answer array,
// we are not using any extra space.
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size() ;
        if(n == 1) return intervals ;
        
        vector<vector<int> > ans ;
        sort(intervals.begin(), intervals.end()) ;
        
        for (int i = 0; i < n; i++) {
            // if the current interval does not
            // lie in the last interval:
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            }
            // if the current interval
            // lies in the last interval:
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        
        return ans ;
    }
};