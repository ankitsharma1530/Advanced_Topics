// class Solution {
// public:
//     int solve(int target, int step,int ind){
        
//         if(ind>=target){
//             return 0;
//         }
//         int ans = 1+min(solve(target,step+1,ind+step),solve(target,step+1,ind-step));
//         return ans;
//     }
//     int reachNumber(int target) {
//         return solve(target,1,0);
//     }
// };

// NOTE -> above i try to solve with DP, but we can conclude that this is not a dp problem as the base condn are not there . 

class Solution {
public:

int reachNumber(int target) {
    if(target<0){
    target=-target;
}
    int step=0;
    int sum=0;
    while(true)
    {
        step++;
        sum=sum+step;
        if(sum==target)
        {
            return step;
        }
        else if(sum>target && (sum-target)%2==0)
        {
            return step;
        }
    }
}
};
