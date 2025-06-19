class Solution {
public:
    bool isPossible(vector<int>& piles, int n, int h, long long mid){
        long long hrs = 0;
        for(int val : piles){
            hrs += ((val-1)/mid)+1;
        }
        return hrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if(h < n ) return -1;
        long long s = 1, e = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(s <= e){
            long long mid = s+(e-s)/2;
            if(isPossible(piles, n, h, mid)){
                ans = mid;
                e = mid-1;
            } else {
                s = mid+1;
            }
        }
        return ans;
    }
};