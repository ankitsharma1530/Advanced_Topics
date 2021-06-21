class Solution {
public:
    string getHint(string secret, string guess) {
        int count = 0;
        vector<bool>vis(secret.size(),false);
        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                vis[i]=true;
                count++;
            }
        }
        unordered_map<char,int>ump;
        for(int i=0;i<secret.length();i++){
            if(!vis[i]){
                ump[secret[i]]++;
            }
        }
        int count2 = 0;
        for(int i=0;i<guess.length();i++){
            if(ump[guess[i]]>0 and vis[i]==false){
                count2++;
                ump[guess[i]]--;
            }
        }
        string res ="";
        res+=to_string(count);
        res+="A";
        res+=to_string(count2);
        res+="B";
        
        return res;
    }
};
