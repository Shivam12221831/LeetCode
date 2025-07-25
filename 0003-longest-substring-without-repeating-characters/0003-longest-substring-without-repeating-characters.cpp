class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int maxLen = 0;
        vector<int> ch(256, -1);
        int left = 0;
        int right = 0;
        while(right < len){
            if(ch[s[right]] != -1){
                left = max(left, ch[s[right]]+1);
            }
            ch[s[right]] = right;
            maxLen = max(maxLen, right-left+1);
            right++;
        }
        return maxLen;
    }
};