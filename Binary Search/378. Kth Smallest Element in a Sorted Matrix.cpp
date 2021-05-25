class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
       if(k==1)
       {
           return m[0][0];
       }
           priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n = m.size();
        int x = m[0].size();
        for(int i=0;i<n;i++)
        {
            pq.push(make_pair(m[i][0],make_pair(i,0)));
        }
        int res = -1;
        while(k--)
        {
            auto temp = pq.top();
            pq.pop();
            int ele = temp.first;
            int i = temp.second.first;
            int j = temp.second.second;
            res = ele;
            if(j!=x-1)
            {
                pq.push({m[i][j+1],{i,j+1}});
            }
        }
        return res;
    }
};
