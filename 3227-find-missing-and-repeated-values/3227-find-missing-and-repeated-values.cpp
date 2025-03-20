class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> sample(grid.size()*grid.size()+1, 0);
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                sample[grid[i][j]]++;
            }
        }
        int a = 0, b = 0;
        for(int i=1; i<grid.size()*grid.size()+1; i++){
            if(sample[i] == 2){
                a = i;
            }
            if(sample[i] == 0){
                b = i;
            }
        }
        return {a,b};
    }
};