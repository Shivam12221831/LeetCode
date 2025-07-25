class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int left = 0;
        int right = 0;
        unordered_set<int> st;
        int maxLen = 0;
        while(right < len){
            if(st.find(s[right]) != st.end()){
                while(left < right && s[left] != s[right]){
                    st.erase(s[left]);
                    left++;
                }
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxLen = max(maxLen, right-left+1);
            right++;
        }
        return maxLen;
    }
};