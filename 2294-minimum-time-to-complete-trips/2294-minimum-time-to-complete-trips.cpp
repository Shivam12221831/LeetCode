class Solution {
public:
    bool isPossible(vector<int>& time, int n, int totalTrips, long long mid){
        long long total = 0;
        for(int val : time){
            total += mid / val;
            if(total >= totalTrips) return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long s = 1, e = (long long)*min_element(time.begin(), time.end())*totalTrips;
        int n = time.size();
        long long ans = e;
        while(s<=e){
            long long mid = s+(e-s)/2;
            if(isPossible(time, n, totalTrips, mid)){
                ans = mid;
                e = mid-1;
            } else {
                s = mid+1;
            }
        }
        return ans;
    }
};