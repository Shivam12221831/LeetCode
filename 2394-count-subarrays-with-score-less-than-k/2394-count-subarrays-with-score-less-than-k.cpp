class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0;
        int n = nums.size();
        int l = 0, r = 0;
        long long count = 0;
        while(r < n){
            sum += nums[r];
            while(l<=r && sum * (r-l+1) >= k){
                sum -= nums[l];
                l++;
            }
            count += r-l+1;
            r++;
        }
        return count;
    }
};