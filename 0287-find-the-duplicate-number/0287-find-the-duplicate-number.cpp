class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int val = nums[i];
            if(s.find(val) != s.end()){
                return val;
            }
            s.insert(val);
        }
        return -1;
    }
};