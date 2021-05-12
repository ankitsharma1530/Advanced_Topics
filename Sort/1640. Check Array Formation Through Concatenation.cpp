class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& p) {
        unordered_map<int,vector<int>>ump;
        for(auto x:p)
        {
            ump[x[0]] = x;
        }
        int i = 0;
        int n = arr.size();
        while(i<n)
        {
            // return false
            if(ump.find(arr[i])==ump.end())
            {
                return false;
            }
            int ind = i;
            for(int j=0;j<ump[arr[ind]].size();j++)
            {
                if(arr[i]!=ump[arr[ind]][j])
                {
                    return false;
                }
                i++;
            }
            // i++;
        }
        return true;
    }
};
