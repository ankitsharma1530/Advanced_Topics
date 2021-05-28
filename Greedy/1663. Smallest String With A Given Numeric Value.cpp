class Solution {
public:
    string getSmallestString(int n, int k) {
        unordered_map<int,char>ump;
        char c = 'a';
        for(int i=1;i<=26;i++){
            ump[i]=c;
            c++;
        }
        string res = "";
        while(n--){
            int temp = k-n;
            if(temp<=26){
                res.push_back(ump[temp]);
                k=k-temp;
            }
            else{
                res.push_back('z');
                k=k-26;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
};
