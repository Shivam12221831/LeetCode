class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int firstSum = 0;
        for(int i=0; i<k; i++){
            firstSum += cardPoints[i];
        }

        int maxSum = firstSum;

        for(int i=1; i<=k; i++){
            firstSum -= cardPoints[k-i];
            firstSum += cardPoints[n-i];
            maxSum = max(maxSum, firstSum);
        }
        return maxSum;
    }
};