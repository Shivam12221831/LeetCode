class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n, 0);
        vector<int> rmax(n, 0);
        for(int i=0; i<n; i++){
            if(i == 0){
                lmax[i] = height[i];
            } else {
                lmax[i] = max(lmax[i-1], height[i]);
            }
        }
        for(int i=n-1; i>=0; i--){
            if(i==n-1) rmax[i] = height[i];
            else rmax[i] = max(rmax[i+1], height[i]);
        }
        int total_cap = 0;
        for(int i=0; i<n; i++){
            total_cap += min(lmax[i], rmax[i]) - height[i];
        }
        return total_cap;
    }
};