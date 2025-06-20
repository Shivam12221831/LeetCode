class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int ans = 0;
        unordered_map<int, int> m;
        while(right < nums.size()){
            m[nums[right]]++;
            while(m[nums[right]] > k){
                m[nums[left]]--;
                left++;
            }
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};