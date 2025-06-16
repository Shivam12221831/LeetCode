class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size()-1;
        int res = INT_MAX;
        while(s <= e){
            int mid = s + (e-s) / 2;
            res = min(res, nums[mid]);
            if(nums[s] <= nums[mid]){
                res = min(res, nums[s]);
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return res;
    }
};