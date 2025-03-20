class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(); int n = matrix[0].size();
        int sRow = 0, eRow = m-1, sCol = 0, eCol = n-1;
        vector<int> ans;
        while(sRow <= eRow && sCol <= eCol){
            for(int j=sCol; j<=eCol; j++){
                ans.push_back(matrix[sRow][j]);
            }
            for(int i=sRow+1; i<=eRow; i++){
                ans.push_back(matrix[i][eCol]);
            }
            for(int j=eCol-1; j>=sCol; j--){
                if(sRow == eRow){
                    break;
                }
                ans.push_back(matrix[eRow][j]);
            }
            for(int i=eRow-1; i>=sRow+1; i--){
                if(sCol == eCol){
                    break;
                }
                ans.push_back(matrix[i][sCol]);
            }
            sRow++, eRow--, sCol++, eCol--;
        }
        return ans;
    }
};