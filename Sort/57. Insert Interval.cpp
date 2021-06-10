

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        int i = 0, n = intervals.size();
        //  the new interval is after the range of other interval, so we can leave the              current interval baecause the new one does not overlap with it
        while(i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i++]);
        }
        // overlap case
        while (i < n && intervals[i][0] <= newInterval[1]) {   
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        res.push_back(newInterval);
        
        // if any elements left
        while (i < n)      
            res.push_back(intervals[i++]);

        return res;  
    }

};
