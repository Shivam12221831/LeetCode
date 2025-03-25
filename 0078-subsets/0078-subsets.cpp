class Solution {
public:
    void printSubsets(vector<int> &nums, vector<int> &res, int i, vector<vector<int>> &allSubsets){
        if(i==nums.size()){
            allSubsets.push_back(res);
            return;
        }
        res.push_back(nums[i]);
        printSubsets(nums, res, i+1, allSubsets);

        res.pop_back();
        printSubsets(nums, res, i+1, allSubsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> res;
        int i = 0;
        printSubsets(nums, res, i, allSubsets);
        return allSubsets;
    }
};