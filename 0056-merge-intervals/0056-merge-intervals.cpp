class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            int first = intervals[i][0];
            int second = intervals[i][1];
            if(!ans.empty() && ans.back()[1] >= second){
                continue;
            }
            for(int j=i+1; j<n; j++){
                if(intervals[j][0] <= second){
                    second = max(second, intervals[j][1]);
                } else {
                    break;
                }
            }
            ans.push_back({first, second});
        }
        return ans;
    }
};