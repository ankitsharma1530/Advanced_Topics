// time complexity - O(n)


class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.length()){
            return false;
        }
        unordered_map<char,int>ump;
        for(int i=0;i<s.length();i++){
            ump[s[i]]++;
        }
        int oc = 0;
        // int ec = 0;
        for(auto x:ump){
            if(x.second&1){
                oc++;
            }
        }
        if(oc>k){
            return false;
        }
        return true;
    }
};
