class Solution {
public:
    int numRabbits(vector<int>& ans) {
        unordered_map<int,int>ump;
        for(auto x:ans){
            ump[x]++;
        }
        int res =0;
        for(auto x:ump){
            if(x.first==0){
                res+=x.second;
            }
            else{
                int num = x.first + 1;
                int q = ceil((double)x.second/(double)num);
                res+=q*num;
            }
        }
        return res;
    }
};
