class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        vector<int> right(n, 0);
        vector<int> left(n, 0);
        stack<int> s;
        // Right Small Nearest
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }

        // Left Small Nearest
        for(int i=0; i<n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        for(int i=0; i<n; i++){
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] *  width;
            ans = max(currArea, ans);
        }
        return ans;
    }
};