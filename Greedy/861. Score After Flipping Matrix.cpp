class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==0)
            {
                for(int j=0;j<m;j++)
                {
                    grid[i][j] = grid[i][j]?0:1;
                }
            }
        }
        for(int j=1;j<m;j++)
        {
            int c0 =0;
            int c1 =0;
            for(int i=0;i<n;i++)
            {
                if(grid[i][j]==0)
                {
                    c0++;
                }
                else{
                    c1++;
                }
            }
            if(c0>c1)
            {
                for(int i=0;i<n;i++)
                {
                    grid[i][j] = grid[i][j]?0:1;
                }
            }
        }
        
        int res = 0;
        for(int i=0;i<n;i++)
        {
            int num = 0;
            int x = 0;
            for(int j=m-1;j>=0;j--)
            {
                num+=(grid[i][j])*pow(2,x);
                x++;
            }
            res+=num;
        }
        return res;
        
    }
};
