class Solution {
public:
    bool static compare(pair<int,int>&p1,pair<int,int>&p2) {
        return p1.second > p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
       for(auto num : nums)mp[num]++;
       vector<pair<int,int>>vect;
        for(auto c:mp){
            vect.push_back({c.first,c.second});
        }
        sort(vect.begin(),vect.end(),compare);
        vector<int>result;
        if(k>mp.size()) {
            return result;
        }
        for(int i=0;i<k;i++){
            result.push_back(vect[i].first);
        }
        return result;
    }
    
};
