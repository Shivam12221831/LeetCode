class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            vector<int> row;
            for(int j=n-1; j>=0; j--){
                row.push_back(matrix[j][i]);
            }
            ans.push_back({row});
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }
};