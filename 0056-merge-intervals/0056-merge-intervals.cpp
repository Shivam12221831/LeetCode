class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int j = 1;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        if(intervals.empty()) return ans;

        for(int i=0; i<n;){
            int ini = intervals[i][0];
            int final = intervals[i][1];
            while(j<n && final >= intervals[j][0]){
                ini = min(ini, intervals[j][0]);
                final = max(final, intervals[j][1]);
                j++;
            }
            if(i == n-1){
                ans.push_back({intervals[i][0], intervals[i][1]});
            } else{
                ans.push_back({ini, final});
            }
            i = j;
            j++;
        }
        return ans;
    }
};