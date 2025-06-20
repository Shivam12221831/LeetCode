class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int l = 0;
        int r = 0;
        while(l<n && r<n){
            long long product = 1;
            for(int i=l; i<=r; i++){
                product *= nums[i];
            }
            if(product < k){
                count += r-l+1;
                r++;
            } else {
                l++;
            }
        }
        return count;
    }
};