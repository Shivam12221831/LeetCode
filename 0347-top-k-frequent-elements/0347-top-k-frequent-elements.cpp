class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int val : nums){
            m[val]++;
        }
        vector<pair<int, int>> res;
        vector<int> ans;
        for(auto it : m){
            res.push_back({it.second, it.first});
        }
        sort(res.begin(), res.end());
        reverse(res.begin(), res.end());

        for(int i=0; i<k; i++){
            ans.push_back(res[i].second);
        }

        return ans;
    }
};