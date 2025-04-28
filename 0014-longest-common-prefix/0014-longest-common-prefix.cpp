class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string opt = "";
        for(int i=0; i<strs[0].length(); i++){
            char c = strs[0][i];
            bool flag = false;
            for(int j=0; j<strs.size(); j++){
                if(strs[j][i] != c){
                    flag = true;
                    break;
                }
            }
            if(flag) {
                break;
            } else {
                opt += c;
            }
        }
        return opt;
    }
};