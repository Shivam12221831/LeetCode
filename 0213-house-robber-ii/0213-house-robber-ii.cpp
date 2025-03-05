class Solution {
public:
    int robMax(vector<int>& caseX){
        int prev1=0, prev2=0;
        for(int num: caseX){
            int temp = prev1;
            prev1 = max(prev1, prev2+num);
            prev2 = temp;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 0) return 0;

        vector<int> case1(nums.begin(), nums.end()-1);
        vector<int> case2(nums.begin()+1, nums.end());
        int maxSum = max(robMax(case1), robMax(case2));
        return maxSum;
    }
};