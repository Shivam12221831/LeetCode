class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int lastSmaller = INT_MIN;
        int cnt = 0;
        int longest_count = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(nums[i] == lastSmaller) continue;
            if(nums[i]-1 == lastSmaller){
                cnt += 1;
                lastSmaller = nums[i];
            } else {
                cnt = 1;
                lastSmaller = nums[i];
            }
            longest_count = max(longest_count, cnt);
        }
        return longest_count;
    }
};