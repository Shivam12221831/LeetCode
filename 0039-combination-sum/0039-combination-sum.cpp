class Solution {
public:
    set<vector<int>> s;
    void combSum(vector<int>& arr, int idx, vector<int>& combine, vector<vector<int>>& ans, int target){
        if(idx == arr.size() || target < 0){
            return;
        }
        if(target == 0){
            if(s.find(combine) == s.end()){
                ans.push_back({combine});
                s.insert(combine);
            }
            return;
        }
        combine.push_back(arr[idx]);
        combSum(arr, idx+1, combine, ans, target-arr[idx]);
        combSum(arr, idx, combine, ans, target-arr[idx]);
        
        combine.pop_back();
        combSum(arr, idx+1, combine, ans, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        int idx = 0;
        combSum(candidates, idx, combine, ans, target);
        return ans;
    }
};