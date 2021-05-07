class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>arr;
        string temp = "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
            {
                temp.push_back(s[i]);
            }
            else
            {
                arr.push_back(temp);
                temp = "";
            }
        }
        arr.push_back(temp);
        unordered_map<char,string>ump;
        unordered_set<string>st;
        if(pattern.length()!=arr.size())
        {
            return false;
        }
        for(int i=0;i<pattern.length();i++)
        {
            if(ump.find(pattern[i])!=ump.end())
            {
                if(ump[pattern[i]]!=arr[i])
                {
                    return false;
                }
            }
            else
            {
                ump[pattern[i]] = arr[i];
                if(st.find(arr[i])!=st.end())
                {
                    return false;
                }
                else
                {
                    st.insert(arr[i]);
                }
            }
        }
        return true;
    }
};






