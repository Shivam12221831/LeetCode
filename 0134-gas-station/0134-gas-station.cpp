class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, currGas = 0;
        int totalGas = 0, totalCost = 0;
        for(int i=0; i<gas.size(); i++){
            totalGas += gas[i];
        }
        for(int i=0; i<cost.size(); i++){
            totalCost += cost[i];
        }
        if(totalGas < totalCost) return -1;

        for(int i=0; i<gas.size(); i++){
            currGas += gas[i] - cost[i];
            if(currGas < 0){
                start = i+1;
                currGas = 0;
            }
        }

        return start;
    }
};