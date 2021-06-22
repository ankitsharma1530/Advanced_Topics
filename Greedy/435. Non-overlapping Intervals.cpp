class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[0]<b[0];
    }
    
    // 12 34 56 28
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int end = intervals[0][1];
        int res = 0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<end){
                end = min(intervals[i][1],end);
                res++;
            }
            else{
                end = intervals[i][1];
            }
        }
        return res;
    }
};
