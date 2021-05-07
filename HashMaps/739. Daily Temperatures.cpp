class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        // 73 74 75 71 69 72 76 73
        // 1  1  4  2  1  1  0  0
        int n = T.size();
        vector<int>res;
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && T[st.top()]<=T[i])
            {
                st.pop();
            }
            if(st.empty()==true)
            {
                res.push_back(0);
            }
            else
            {
                res.push_back(st.top()-i);
            }
            st.push(i);
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};
