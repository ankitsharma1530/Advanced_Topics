class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // 1st condn
        // every element in word1 should present in word2
        vector<int> v1(26,0),v2(26,0);
        for(int i=0;i<word1.length();i++){
            v1[word1[i]-'a']++;
            
        }
        for(int i=0;i<word2.length();i++){
            v2[word2[i]-'a']++;
        }
        // we will check wether word is present in both strings or not
        for(int i=0;i<26;i++){
            if(v1[i]&&!v2[i] || v2[i]&&!v1[i]){
                return false;
            }
        }
        unordered_map<int,int>ump;
        for(int i=0;i<26;i++){
            ump[v1[i]]++;
        }
        for(int i=0;i<26;i++){
            ump[v2[i]]--;
        }
        
        for(auto& x:ump){
            if(x.second!=0){
                return false;
            }
        }
        return true;
    }
};
