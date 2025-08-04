class Solution {
public:
    bool isDigit(char ch){
        if('0' <= ch && ch <= '9') return true;
        else return false;
    }
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        long long sum = 0;
        int sign = 1;
        while(i<n && s[i] == ' '){
            i++;
        }
        if(i<n && (s[i] == '-' || s[i] == '+')){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        while(i<n && isDigit(s[i])){
            sum = sum * 10 + (s[i] - '0');
            if(sign * sum > INT_MAX) return INT_MAX;
            if(sign * sum < INT_MIN) return INT_MIN;
            i++;
        }

        return (int)(sum*sign);
    }
};