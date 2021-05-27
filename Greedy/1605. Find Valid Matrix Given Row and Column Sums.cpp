class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j] = min(rowSum[i],colSum[j]);
                rowSum[i]-=dp[i][j];
                colSum[j]-=dp[i][j];
            }
        }
        return dp;
    }
};
