class Solution {
public:
    vector<int> generate_row(int row_no){
        vector<int> row;
        long long prev = 1;
        row.push_back(prev);
        for(int i=1; i<row_no; i++){
            prev *= row_no-i;
            prev /= i;
            row.push_back(prev);
        }
        return row;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++){
            ans.push_back(generate_row(i));
        }
        return ans;
    }
};