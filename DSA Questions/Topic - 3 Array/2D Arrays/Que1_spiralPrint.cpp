// LeetCode -> 54. Spiral Matrix
https://leetcode.com/problems/spiral-matrix/description/




// Approch -> 1: Brute Force Approch
// T.C. = O(row * col)
// S.C. = O(row * col)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int total = matrix.size() * matrix[0].size() ;
        int count = 0;
        vector<int> print ;
        //index initialization 
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = matrix.size()-1;
        int endingCol = matrix[0].size()-1;

        while( count < total ){
            //print starting row
            for(int index = startingCol ; index<=endingCol && count<total ; index++){
                print.push_back(matrix[startingRow][index]) ;
                count++;
            }
            startingRow++;

            //print ending column
            for(int index = startingRow ; index<= endingRow && count<total ; index++){
                print.push_back(matrix[index][endingCol]) ;
                count++;
            }
            endingCol--;

            //print ending row
            for(int index = endingCol ; index>= startingCol && count<total ; index--){
                print.push_back(matrix[endingRow][index]) ;
                count++;
            }
            endingRow--;

            //print starting column
            for(int index = endingRow ; index>= startingRow && count<total ; index--){
                print.push_back(matrix[index][startingCol]) ;
                count++;
            }
            startingCol++;
        }
        return print ;
    }
};