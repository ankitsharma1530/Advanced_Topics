class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        // first maximise every number
        // we can only maximise the odd number by multiplying them by 2
        int min_ele = INT_MAX;
        int max_ele = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1){
                nums[i]*=2;
            }
            min_ele = min(min_ele,nums[i]);
            max_ele = max(max_ele,nums[i]);
        }
        int diff = max_ele - min_ele;
        
        // now we will minimize the maximum element
        // we can minimize only when the number is even by divide by 2
        priority_queue<int>pq;
        for(auto x:nums){
            pq.push(x);
        }
        
        while(pq.top()%2==0){
            int t = pq.top();
            pq.pop();
            t = t/2;
            min_ele = min(min_ele,t);
            pq.push(t);
            diff = min(diff,pq.top()-min_ele);
        }
        diff = min(diff,pq.top()-min_ele);
        return diff;
    }
};
