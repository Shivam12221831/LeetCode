class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_map<int, int> mpRow;
        unordered_map<int, int> mpCol;
        // vector<vector<int>> ans(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            // int rowZ = 0;
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    if(mpRow.find(i) == mpRow.end()){
                        mpRow[i] = 1;
                    }
                    mpCol[j] = 1;;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mpRow.find(i) != mpRow.end()){
                    matrix[i][j] = 0;
                }
                if(mpCol.find(j) != mpCol.end()){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};