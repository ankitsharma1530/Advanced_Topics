class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>>res;
        vector<string>ans;
        ans.push_back("Table");
        // map for dishes in sorted order
        map<string,int>ump;
        
        // for all tables make map- jisme hoga ki
        // har table se kitna order ho raha hai
        map<int,map<string,int>>ump1;
        for(auto& x:orders)
        {
            ump[x[2]]++;
            ump1[stoi(x[1])][x[2]]++;
        }
        for(auto& x:ump)
        {
            ans.push_back(x.first);
        }
        res.push_back(ans);
        // total dishes
        int n = ans.size();
        for(auto& m:ump1)
        {
            vector<string>temp;
            temp.push_back(to_string(m.first));
            for(int i=1;i<n;i++)
            {
                temp.push_back(to_string(m.second[ans[i]]));
            }
            res.push_back(temp);
        }
        return res;
        
    }
};
