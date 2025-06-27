class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int val: nums){
            mp[val]++;
        }
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i]) != mp.end() && mp[nums[i]] == 1){
                    return nums[i];
            }
        }
        return -1;
    }
};