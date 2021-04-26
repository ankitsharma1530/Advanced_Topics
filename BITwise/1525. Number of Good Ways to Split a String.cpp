class Solution {
public:
    int numSplits(string s) {
        // acb
        // a-4
        // b-1
        // c-1
        int res = 0;
        // string a="";
        string b=s;
        // unordered_set<char>sa;
        // unordered_set<char>sb;
        unordered_map<char,int>ma;
        unordered_map<char,int>mb;
        for(int i=0;i<s.length();i++)
        {
            mb[s[i]]++;
            // sb.insert(s[i]);
        }
        int i=0;
        int n = s.length();
        while(i<n)
        {
            char c = s[i];
            // sa.insert(c);
            ma[c]++;
            mb[c]--;
            // b=b.substr(1,s.length());
            // cout<<b<<" ";
            if(mb[c]==0)
            {
                mb.erase(c);
            }
            if(ma.size()==mb.size())
            {
                res++;
            }
            i++;
            
        }
        // cout<<endl;
        return res;
    }
};
