class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int end = points[0][1];
        int total= 1;
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=end){
                end = min(end,points[i][1]);
            }
            else{
                total++;
                end = points[i][1];
            }
        }
        return total;
    }
};
// time complexity -> O(nlogn)
