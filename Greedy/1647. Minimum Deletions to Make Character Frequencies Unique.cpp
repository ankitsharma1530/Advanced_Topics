class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>ump;
        for(int i=0;i<s.length();i++){
            ump[s[i]]++;
        }
        vector<int>counts;
        for(auto& x:ump){
            counts.push_back(x.second);
        }
        sort(counts.begin(),counts.end(),greater<>());
        int res = 0;
        for (int i = 0; i <counts.size()-1 ; i++) {
            for (int j = i+1; j <counts.size() ; j++) {
                if (counts[i]>0 && counts[i]==counts[j]){
                    int count = counts[j];
                    counts[j] = count - 1;
                    res++;
                }else
                    break;
            }
        }
        return res;
    }
};1647. Minimum Deletions to Make Character Frequencies Unique
