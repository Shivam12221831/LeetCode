class Solution {
public:
    string rle(string str){
        string rt = "";
        int len = str.length();
        for(int i=0; i<len; ){
            char ch = str[i];
            int count = 0;
            while(i<len && str[i] == ch){
                count++;
                i++;
            }
            rt += to_string(count);
            rt += ch;
        }
        return rt;
    }
    string countAndSay(int n) {
        string res = "1";
        for(int i=1; i<n; i++){
            res = rle(res);
        }
        return res;
    }
};