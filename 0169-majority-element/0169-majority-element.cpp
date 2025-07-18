class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int ele;
        for(int i=0; i<n; i++){
            if(cnt == 0){
                ele = nums[i];
                cnt++;
            } else if(nums[i] == ele){
                cnt++;
            } else {
                cnt--;
            }
        }
        // if not confirm that arr has a majority ele then use this check
        int final_cnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == ele){
                final_cnt++;
            }
        }
        return (final_cnt > n/2) ? ele : -1;
    }
};