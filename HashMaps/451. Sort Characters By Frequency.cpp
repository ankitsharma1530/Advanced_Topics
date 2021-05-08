class Solution {
public:
    static bool comp(pair<char,int>& a, pair<char,int>& b)
    {
        if(a.second>b.second)
        {
            return true;
        }
        else if(a.second==b.second)
        {
            if(a.first>b.first)
            {
                return true;
            }
            return false;
        }
        return false;
    }
    string frequencySort(string s) {
        unordered_map<char,int>ump;
        for(int i=0;i<s.length();i++)
        {
            ump[s[i]]++;
        }
        vector<pair<char,int>>arr;
        for(auto x:ump)
        {
            arr.push_back(make_pair(x.first,x.second));
        }
        sort(arr.begin(),arr.end(),comp);
        string res = "";
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[i].second;j++)
            res.push_back(arr[i].first);
        }
        return res;
    }
};
