class Solution {
public:
    // time complexity -> O(nlogn)+O(nlogn)
    // O(nlogn) -> for sorting
    // O(nlogn) -> binary search for n times
    static bool cmp(pair<int,int>& a,pair<int,int>& b){
        return a.first<b.first;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int,int>>bs;
        int ind=0;
        for(auto& x:intervals){
            // storing starting time with index
            bs.push_back(make_pair(x[0],ind));
            ind++;
        }
        // sort
        sort(bs.begin(),bs.end(),cmp);
        vector<int>res;
        
        for(auto& x:intervals){
            int end = x[1];
            int i=0;
            int j=bs.size()-1;
            int ans = INT_MAX;
            // find the index of that INTERVAL whose starting point is greater than               // our current ending time
            // as we had to search in logn time hence used binary search
            while(i<=j){
                int mid = i+(j-i)/2;
                if(bs[mid].first>=end){
                    ans = bs[mid].second;
                    j=mid-1;
                }
                else{
                    i=mid+1;
                }
            }
            if(ans==INT_MAX){
                res.push_back(-1);
            }
            else{
                res.push_back(ans);
            }
        }
        return res;
    }
};
