class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        if(a[0]<=b[0])
        {
            return true;
        }
        return false;
    }
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int dis = INT_MIN;
        for(int i=1;i<points.size();i++)
        {
            dis = max(dis,points[i][0]-points[i-1][0]);
        }
        return dis;
    }
};
