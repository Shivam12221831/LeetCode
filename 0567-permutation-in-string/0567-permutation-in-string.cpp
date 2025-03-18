class Solution {
public:
    bool isFreqSame(int freq1[], int freq2[]){
        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for(int i=0; i<s1.length(); i++){
            freq[s1[i] - 'a']++;
        }

        int wnSize = s1.length();
        for(int i=0; i<s2.length(); i++){
            int wnIdx = 0, idx = i;
            int wnfreq[26] = {0};
            while(wnIdx < wnSize && idx < s2.length()){
                wnfreq[s2[idx] - 'a']++;
                wnIdx++, idx++;
            }
            if(isFreqSame(freq, wnfreq)){
                return true;
            }
        }
        return false;
    }
};