class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int l = 0, r = 0;
        int currCost = 0;
        int maxLen = 0;
        while(r < n){
            currCost += abs(s[r] - t[r]);
            if(currCost <= maxCost){
                int len = r-l+1;
                maxLen = max(maxLen, len);
            } else {
                currCost -= abs(s[l] - t[l]);
                l++;
            }
            r++;
        }
        return maxLen;
    }
};