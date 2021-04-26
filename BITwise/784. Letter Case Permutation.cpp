class Solution {
public:
    vector<string>res;
    void solve(string S, string temp, int ind,int n)
    {
        if(ind>=n)
        {
            res.push_back(temp);
            return;
        }
        if(isdigit(S[ind])==true)
        {
            solve(S,temp+S[ind],ind+1,n);
        }
        else
        {
            // one time we will call as small letter
            char c1 = tolower(S[ind]);
            solve(S,temp+c1,ind+1,n);
            // at one time as captial letter
            char c2 = toupper(S[ind]);
            solve(S,temp+c2,ind+1,n);
        }
    }
    vector<string> letterCasePermutation(string S) {
        int n = S.length();
        solve(S,"",0,n); 
        return res;
    }
};
