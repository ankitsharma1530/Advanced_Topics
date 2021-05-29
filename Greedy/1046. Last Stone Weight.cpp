class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        priority_queue<int>q;
        for(auto& x:nums){
            q.push(x);
        }
        while(q.size()>1){
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            x=x-y;
            
            q.push(x);
            
        }
        return q.top();
    }
};
