class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int longest_count = 0;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        for(auto it : st){
            if(st.find(it-1) == st.end()){
                int cnt = 1;
                while(st.find(it+1) != st.end()){
                    it = it+1;
                    cnt++;
                }
                longest_count = max(longest_count, cnt);
            }
        }
        return longest_count;
    }
};