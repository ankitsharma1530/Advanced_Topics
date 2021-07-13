class Solution {
public:
    // time complexity -> O(nlogn) + O(n)
    int find(int node,vector<int>& par){
        if(par[node]==node){
            return node;
        }
        return par[node] = find(par[node],par); // path compression
        // without this path compression you will get TLE
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vector<vector<int>>adj(n);
        for(auto x:pairs){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>par(n);
        for(int i=0;i<n;i++){
            par[i] = i;
        }
        for(auto x:pairs){
            int par1 = find(x[0],par);
            int par2 = find(x[1],par);
            if(par1!=par2){
                par[par1] = par2;
            }
        }
        unordered_map<int,vector<int>>ump;
        for(int i=0;i<n;i++){
            ump[find(i,par)].push_back(i);
        }
        for(auto x:ump){
            string temp = "";
            for(auto i:x.second){
                temp.push_back(s[i]);
            }
            sort(temp.begin(),temp.end());
            int j = 0;
            for(auto i:x.second){
                s[i] = temp[j++];
            }
        }
        return s;
    }
};
