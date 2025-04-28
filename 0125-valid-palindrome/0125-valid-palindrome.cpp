class Solution {
public:
    bool isAlphaNumeric(char c){
        if((tolower(c) >= 'a' && tolower(c) <= 'z') || (c >= '0' && c <= '9')){
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.length();
        while(i < j){
            if(!isAlphaNumeric(s[i])){
                i++;
                continue;
            }
            if(!isAlphaNumeric(s[j])){
                j--;
                continue;
            }
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
            i++; j--;
        }
        return true;
    }
};