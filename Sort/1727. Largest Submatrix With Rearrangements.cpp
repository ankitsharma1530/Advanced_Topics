class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& dp) {
        int n = dp.size();
        int m = dp[0].size();
        int ans = 0;
        vector<int>heights(m,0);
        // traverse for each row
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]==0)
                {
                    heights[j]=0;
                }
                else
                {
                    heights[j]+=1;
                }
            }
            vector<int>temp = heights;
            sort(temp.begin(),temp.end(),greater<>());
            for(int ii=0;ii<m;ii++)
            {
                ans = max({ans,temp[ii],temp[ii]*(ii+1)});
            }
        }
        return ans;
    }
};
