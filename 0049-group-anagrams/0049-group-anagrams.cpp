class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> ans;
        for(string s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            m[temp].push_back(s);
        }
        for(auto it : m){
            ans.push_back(it.second);
        }
        return ans;
    }
};