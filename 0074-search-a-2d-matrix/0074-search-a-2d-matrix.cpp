class Solution {
public:
    bool searchInRow(vector<vector<int>>& matrix, int target, int n, int midR){
        int s = 0, e = n-1;
        while(s <= e){
            int mid = s + (e -s) / 2;
            if(target == matrix[midR][mid]){
                return true;
            }else if(target > matrix[midR][mid]){
                s = mid+1;
            } else {
                e = mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int sR = 0, eR = m-1;
        while(sR <= eR){
            int midR = sR + (eR - sR) / 2;
            if(target <= matrix[midR][n-1] && target >= matrix[midR][0]){
                return searchInRow(matrix, target, n, midR);
            } else if(target < matrix[midR][0]){
                eR = midR - 1;
            } else {
                sR = midR + 1;
            }
        }
        return false;
    }
};