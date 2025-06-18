class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size()-1;
        int res = INT_MAX;
        while(s <= e){
            int mid = s + (e-s) / 2;
            res = min(nums[mid], res);
            if(nums[s] == nums[mid] && nums[mid] == nums[e]){
                s++, e--;
            }
            else if(nums[s] <= nums[mid]){
                res = min(nums[s], res);
                s = mid+1;
            } else {
                e = mid-1;
            }
        }
        return res;
    }
};