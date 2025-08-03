class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        bool flag = false;
        string res = "";
        for(int i=0; i<strs[0].size(); i++){
            char ch = strs[0][i];
            for(int j=0; j<n; j++){
                if(strs[j][i] != ch){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            else res += ch;
        }
        return res;
    }
};