class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>res;
        if(s.length()<10){
            return res;
        }
        string temp = "";
        for(int i=0;i<10;i++){
            temp.push_back(s[i]);
        }
        unordered_map<string,int>st;
        // st.insert(temp);
        st[temp]=1;
        for(int i=10;i<s.length();i++){
            temp = temp.substr(1);
            temp+=s[i];
            st[temp]++;
        }
        for(auto x:st){
            if(x.second>1)
            res.push_back(x.first);
        }
        return res;
    }
};
