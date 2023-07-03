// LeetCode -> 118. Pascal's Triangle
https://leetcode.com/problems/pascals-triangle/


// Approch -> 1:
// T.C. = O(n*n*r) ~ O(n3), where n = number of rows, and r = column index.
// S.C. = In this case, we are only using space to store the answer. That is why space complexity can be still considered as O(1).
class Solution {
    
    int nCr(int n, int r) {
        long long res = 1;

        // calculating nCr:
        for (int i = 0; i < r; i++) {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return (int)(res);
    }

public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        //Store the entire pascal's triangle:
        for (int row = 1; row <= numRows; row++) {
            vector<int> tempLst; // temporary list
            for (int col = 1; col <= row; col++) {
                tempLst.push_back(nCr(row - 1, col - 1));
            }
            ans.push_back(tempLst);
        }
        return ans;
    }
};


// Optimal Approach
// Time Complexity: O(n2), where n = number of rows(given).
// Reason: We are generating a row for each single row. The number of rows is n. And generating an entire row takes O(n) time complexity.
// Space Complexity: In this case, we are only using space to store the answer. That is why space complexity can still be considered as O(1).
class Solution {
    
    vector<int> generateRow(int row) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1); //inserting the 1st element

        //calculate the rest of the elements:
        for (int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        //store the entire pascal's triangle:
        for (int row = 1; row <= numRows; row++) {
            ans.push_back(generateRow(row));
        }
        return ans;
    }
};