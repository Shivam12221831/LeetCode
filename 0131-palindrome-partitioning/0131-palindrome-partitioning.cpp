class Solution {
public:
    bool isPalindrome(string s){
        int st=0, end=s.length()-1;
        while(st < end){
            if(s[st++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    void getAllParts(string s, vector<string> &partitions, vector<vector<string>> &ans){
        if(s.size() == 0){
            ans.push_back(partitions);
            return;
        }
        for(int i=0; i<s.size(); i++){
            string part = s.substr(0, i+1);
            if(isPalindrome(part)){
                partitions.push_back(part);
                getAllParts(s.substr(i+1), partitions, ans);

                partitions.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;
        getAllParts(s, partitions, ans);
        return ans;
    }
};