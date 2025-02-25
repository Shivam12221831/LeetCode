class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> indexedNums;
        for(int i=0; i<nums.size(); i++){
            indexedNums.push_back({nums[i], i});
        }
        sort(indexedNums.begin(), indexedNums.end());
        int s=0, e=nums.size()-1;
        while(s<e){
            int pairSum=indexedNums[s].first+indexedNums[e].first;
            if(pairSum>target){
                e--;
            }else if(pairSum<target){
                s++;
            }else{
                return {indexedNums[s].second, indexedNums[e].second};
            }
        }
        return {};
    }
};