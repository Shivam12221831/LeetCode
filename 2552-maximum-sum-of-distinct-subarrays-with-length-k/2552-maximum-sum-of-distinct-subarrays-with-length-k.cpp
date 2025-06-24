class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> s;
        int l = 0, r = 0;
        long long currSum = 0;
        long long maxSum = 0;
        while(r < n){
            while(s.contains(nums[r])){
                s.erase(nums[l]);
                currSum -= nums[l];
                l++;
            }

            s.insert(nums[r]);
            currSum += nums[r];

            if(r-l+1 == k){
                maxSum = max(maxSum, currSum);

                s.erase(nums[l]);
                currSum -= nums[l];
                l++;
                r++;
            } else {
                r++;
            }
        }
        return maxSum;
    }
};