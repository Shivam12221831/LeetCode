class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int countZero = 0;
        int n = nums.size();
        int totalMax = INT_MIN;
        // int total = 0;
        while(r < n){
            // if(nums[r] == 1){
            //     total++;
            //     r++;
            // }else {
            //     if(countZero < k){
            //         countZero++;
            //         total++;
            //         r++;
            //     } else {
            //         total = 1;
            //         countZero = 1;
            //         l++;
            //     }
            // }
            // totalMax = max(totalMax, total);
            if(nums[r] == 0) countZero++;
            while(countZero > k){
                if(nums[l] == 0) countZero--;
                l++;
            }
            int len = r-l+1;
            totalMax = max(totalMax, len);
            r++;
        }
        return totalMax;
    }
};