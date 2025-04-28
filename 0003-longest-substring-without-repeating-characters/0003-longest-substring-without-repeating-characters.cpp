class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int maxL = 0;
        vector<int> alpha(256, -1);
        while(r<s.length()){
            if(alpha[s[r]] != -1 && alpha[s[r]] >= l){
                l = alpha[s[r]]+1;
            }
            int len = r-l+1;
            maxL = max(maxL, len);
            alpha[s[r]] = r;
            r++;
        }
    return maxL;
    }
};