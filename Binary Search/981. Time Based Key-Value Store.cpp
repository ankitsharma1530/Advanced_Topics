class TimeMap {
public:
    /** Initialize your data structure here. */
    
    // unique - > foo
    // repeated -> bar2 , timestamp
    unordered_map<string,vector<pair<int,string>>>ump;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(ump.find(key)==ump.end()){
            ump[key].push_back({timestamp,value});
        }
        else{
            ump[key].push_back({timestamp,value});
        }
    }
    
    string get(string key, int timestamp) {
        if(ump.find(key)==ump.end()){
            return "";
        }
        string res ;
        // for(int i=0;i<ump[key].size();i++){
        //     if(ump[key][i].first>timestamp){
        //         return res;
        //     }
        //     res = ump[key][i].second;
        // }
        
        // binary search
        int i=0;
        int j=ump[key].size()-1;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(ump[key][mid].first<=timestamp){
                res = ump[key][mid].second;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        // return res;
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
