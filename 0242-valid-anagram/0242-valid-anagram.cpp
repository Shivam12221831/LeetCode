class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        
        int count[26] = {0};

        for(char c : s){
            count[c - 'a']++;
        }

        for(char c : t){
            count[c - 'a']--;
        }

        for(int val : count){
            if(val != 0) return false;
        }
        return true;
    }
};