class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        long long sum = 0;
        vector<int> avgs(n, -1);
        while(r < n){
            sum += nums[r];
            int len = r-l+1;
            if(len == 2*k+1){
                avgs[l+k] = sum/(2*k+1);
                sum -= nums[l];
                l++; 
            }
            r++;
        }
        return avgs;
    }
};