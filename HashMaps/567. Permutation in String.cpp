class Solution {
public:
    // with usual hashmap this will show TLE
    // hence we had used vector of 26 length
    // time complexity ->O(s1.length())+O(26*(s2.length-s1.length))
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return false;
        }
        vector<int>ump1(26,0);
        for(auto x:s1){
            ump1[x-'a']++;
        }
        vector<int>ump2(26,0);
        for(int i=0;i<s1.length();i++){
            ump2[s2[i]-'a']++;
        }
        int flag = 1;
        for(int j=0;j<26;j++){
            if(ump1[j]!=ump2[j]){
                flag=0;
                break;
            }
        }   
        if(flag){
            return true;
        }
        for(int i=s1.length();i<s2.length();i++){
            
            ump2[s2[i-s1.length()]-'a']--;
            ump2[s2[i]-'a']++;
            int flag = 1;
            for(int j=0;j<26;j++){
                if(ump1[j]!=ump2[j]){
                    flag=0;
                    break;
                }
            }   
            if(flag){
                return true;
            }
        }
        return false;
    }
};
