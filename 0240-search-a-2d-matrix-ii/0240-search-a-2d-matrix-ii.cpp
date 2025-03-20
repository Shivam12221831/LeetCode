class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size()-1, c = 0;
        while(r>=0 && c<matrix[0].size()){
            if(target == matrix[r][c]){
                return true;
            } else if(target > matrix[r][c]){
                c++;
            } else {
                r--;
            }
        }
        return false;
    }
};