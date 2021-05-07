class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // 1  2  3  2  1 .. 1 2 3 2 1
      //   2  3 -1  3  2
        stack<int>s;
        // we will fill the stack for the circular purpose
        for(int i=nums.size()-1;i>=0;i--)
        {
            s.push(nums[i]);
        }
        vector<int>res;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(s.empty())
            {
                res.push_back(-1);
            }
            else if(!s.empty() && s.top()>nums[i])
            {
                res.push_back(s.top());
            }
            else if(!s.empty() && s.top()<=nums[i])
            {
                while(!s.empty() && s.top()<=nums[i])
                {
                    s.pop();
                }
                if(s.empty())
                {
                    res.push_back(-1);
                }
                else
                {
                    res.push_back(s.top());
                }
            }
            s.push(nums[i]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
