class Solution {
public:
    int value(char ch){
        if(ch == 'I') return 1;
        else if(ch == 'V') return 5;
        else if(ch == 'X') return 10;
        else if(ch == 'L') return 50;
        else if(ch == 'C') return 100;
        else if(ch == 'D') return 500;
        else if(ch == 'M') return 1000;
        else return -1;
    }
    int romanToInt(string s) {
        int n = s.length();
        int res = 0;
        for(int i=0; i<n; i++){
            int curr = value(s[i]);
            if(i+1 < n){
                int next = value(s[i+1]);
                if(next <= curr){
                    res += curr;
                } else {
                    res += next - curr;
                    i++;
                }
            } else {
                res += curr;
            }
        }
        return res;
    }
};