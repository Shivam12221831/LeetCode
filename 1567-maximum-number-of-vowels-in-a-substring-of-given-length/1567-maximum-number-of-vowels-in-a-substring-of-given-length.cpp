class Solution {
public:
    bool isVowel(char ch){
        if(ch =='a' || ch =='e' || ch =='o' || ch =='i' || ch =='u'){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int n = s.length();
        int vowelCount = 0;
        for(int i=0; i<k-1; i++){
            if(isVowel(s[i])){
                vowelCount++;
            }
        }
        int l = 0;
        int r = k-1;
        int maxCount = INT_MIN;
        while(r<n){
            if(isVowel(s[r])){
                vowelCount++;
            }

            maxCount = max(maxCount, vowelCount);

            if(isVowel(s[l])){
                vowelCount--;
            }
            l++;
            r++;
        }
        return maxCount;
    }
};