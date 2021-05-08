class Solution {
public:
     int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
         // either we have all zeros or we have all ones in rows
         // 001 = 110
         // as we flip first two columns then 001 become 111
         // and 110 become 000
         // so we only have to determine wether they have same property or not
         unordered_map<string,int>ump;
         int res = 0; // count of number of rows
         for(auto& x:matrix)
         {
             string s = "";
             int top_ele = x[0];
             // traverse each row
             for(int i=0;i<x.size();i++)
             {
                 if(top_ele==x[i])
                 {
                     s.push_back('1');
                 }
                 else
                 {
                     s.push_back('0');
                 }
             }
             ump[s]++;
         }
         for(auto& x:ump)
         {
             res= max(res,x.second);
         }
         return res;
     }
 };
// static auto _ = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

// class Solution {
// public:
//     int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
//         unordered_map<string, int> map;
        
//         int best = 0;
//         int m = matrix.size();
//         if (!m) return 0;
//         int n = matrix[0].size();
        
//         for (int i = 0; i < m; ++i) {
//             int offset = matrix[i][0];
//             string s(n, '0');
//             for (int j = 0; j < n; ++j) {
//                 if ((matrix[i][j]+offset) % 2) {
//                     s[j] = '1';
//                 }
//             }
//             best = max(best, ++map[s]);
//         }
        
//         return best;
//     }
// };
