class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].length();
        int count = 0;
        for(int j=0;j<m;j++)
        {
            char c = strs[0][j];
            for(int i=1;i<n;i++)
            {
                if(c>strs[i][j])
                {
                    count++;
                    break;
                }
                c = strs[i][j];
            }
        }
        return count;
    }
};
