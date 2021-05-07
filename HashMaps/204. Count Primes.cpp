class Solution {
public:
    int countPrimes(int n) {
        // sieve
        vector<bool>vis(n,false);
        for(int i=2;i<sqrt(n);i++)
        {
            if(vis[i]==false)
            {
                for(int j=i*i;j<n;j+=i)
                {
                    vis[j]=true;
                }
            }
        }
        int count = 0;
        for(int i=2;i<n;i++)
        {
            if(vis[i]==false)
            {
                count++;
            }
        }
        return count;
    }
};
