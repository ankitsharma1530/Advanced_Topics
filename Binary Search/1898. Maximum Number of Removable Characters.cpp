class Solution {
public:
    // why use of binary search ?
    // This problem has monotonicity in it -- there must be a k that for all i <= k,             // removing the first i characters is valid; for all i > k, removing the first i             // characters is invalid.
    // We can use binary search to search this maximum valid k.
    
    bool ischeck(string s, string p, vector<int>& removable, int mid_ind){
        for(int i=0;i<=mid_ind;i++){
            s[removable[i]]='*';
        }
        int a=0;
        int b=0;
        int n=s.length();
        int m=p.length();
        while(b<m and a<n){
            if(s[a]==p[b]){
                b++;
            }
            a++;
            
        }
        return b==m;
    }
     
    int maximumRemovals(string s,string p, vector<int>& removable) {
        int i=0;
        int j=removable.size()-1;
        int res = 0;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(ischeck(s,p,removable,mid)==true){
                res = mid+1;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return res;
    }
};
