// O(n) solution

class Solution {
public:
    // this is not an easy problem
    // this is having a lot of logic in it
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum_gas = 0;
        int sum_cost = 0;
        
        // first thing we had to understand
        // if the total sum of gas is less than cost then we cant travel a circle
        // hence we gonna return -1
        for(int i=0;i<gas.size();i++){
            sum_gas+=gas[i];
            sum_cost+=cost[i];
        }
        if(sum_gas<sum_cost){
            return -1;
        }
        int balance = 0;
        int res = 0;
        // other wise we will check for each index
        // this logic is as much as kadane's algo
        for(int i=0;i<gas.size();i++){
            balance += gas[i]-cost[i];
            if(balance<0){
                balance = 0;
                res = i+1;
            }
        }
        return res;
    }
};
