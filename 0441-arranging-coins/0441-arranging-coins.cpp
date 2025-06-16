class Solution {
public:
    int arrangeCoins(int n) {
        int s = 1, e = n;
        long long res = -1;
        long long sum = 0;
        while(s <= e){
            long long mid = s + (e-s) / 2;
            sum = mid*(mid+1)/2;
            if(sum <= n){
                res = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return res;
    }
};