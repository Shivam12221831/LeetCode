class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int cnt = 1;
        int j = 1;
        for(int i=1; i<n; i++){
            if(nums[i] == prev) continue;
            else {
                nums[j] = nums[i];
                j++;
                cnt++;
                prev = nums[i];
            }
        }
        return cnt;
    }
};