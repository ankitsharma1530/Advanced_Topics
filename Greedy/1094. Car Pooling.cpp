class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[1]<b[1]){
            return true;
        }
        else if(a[1]==b[1]){
            return a[2]<b[2];
        }
        return false;
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),cmp);
        int limit = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(auto& x:trips){
            if(!q.empty()){
                while(!q.empty() && q.top().first<=x[1]){
                    limit-=q.top().second;
                    q.pop();
                }
            }
            
            limit+=x[0];
            if(limit>capacity){
                return false;
            }
            q.push(make_pair(x[2],x[0]));
        }
        return true;
    }
};
