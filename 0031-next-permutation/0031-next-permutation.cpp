class Solution {
public:
    void reverseArr(vector<int> &nums, int s, int e){
        while(s <= e){
            swap(nums[s], nums[e]);
            s++;
            e--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), piv = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                piv = i;
                break;
            }
        }
        if(piv == -1){
            reverseArr(nums, 0, n-1);
            return;
        }
        for(int i=n-1; i>piv; i--){
            if(nums[piv] < nums[i]){
                swap(nums[i], nums[piv]);
                break;
            }
        }
        reverseArr(nums, piv+1, n-1);
    }
};