class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for(int val: nums){
            int freq=0;
            for(int el: nums){
                if(el == val){
                    freq++;
                }
            }
            int n = nums.size();
            if(freq > (n/2)){
                return val;
            }
        }
        return -1;
    }
};