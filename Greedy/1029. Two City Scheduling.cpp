class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int res = 0;
        for(int i=0;i<costs.size();i++){
            res+=costs[i][0];
        }
        vector<int>v;
        for(int i=0;i<costs.size();i++){
            v.push_back(costs[i][1]-costs[i][0]);
        }
        int n = costs.size();
        sort(v.begin(),v.end());
        for(int i=0;i<n/2;i++){
            res+=v[i];
        }
        return res;
    }
};
