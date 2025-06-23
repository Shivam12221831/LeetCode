class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxEle = *max_element(nums.begin(), nums.end());
        int l = 0;
        int r = 0;
        int maxCount = 0;
        long long res = 0;
        int n = nums.size();
        while(r < n){
            if(nums[r] == maxEle) maxCount++;
            while(maxCount >= k){
                if(nums[l] == maxEle) maxCount--;
                l++;
            }
            res += l;
            r++;
        }
        return res;
    }
};