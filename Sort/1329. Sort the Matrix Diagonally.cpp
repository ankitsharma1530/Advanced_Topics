class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int,multiset<int>>ump;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                ump[i-j].insert(mat[i][j]);
            }
        }
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                mat[i][j] = *ump[i-j].begin();
                ump[i-j].erase(ump[i-j].begin());
            }
        }
        return mat;
    }
};
