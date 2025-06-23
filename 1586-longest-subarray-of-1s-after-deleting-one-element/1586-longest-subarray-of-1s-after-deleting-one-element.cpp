class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int zeroRemoved = 0;
        int l = 0, r = 0;
        int maxLen = INT_MIN;
        if(n == 1 && nums[0] == 0) return 0;
        while(r < n){
            if(nums[r] == 0) zeroRemoved++;
            if(nums[r] == 0 && zeroRemoved > 1){
                while(nums[l] != 0){
                    l++;
                }
                l++;
                zeroRemoved--;
            }

            int len = r-l+1;
            maxLen = max(maxLen, len);
            r++;
        }
        return maxLen ? maxLen - 1 : 0;
    }
};