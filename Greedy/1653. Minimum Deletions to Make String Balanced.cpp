class Solution {
public:
    int minimumDeletions(string s) {
        if(s.length()==1){
            return 0;
        }
        int n = s.length();
        int left[n];
        int right[n];
        int c = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                c++;
            }
            left[i] = c;
        }
        c = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a'){
                c++;
            }
            right[i] = c;
        }
        int min_del = INT_MAX;
        for(int i=0;i<n;i++){
            if(i==0){
                min_del = min(min_del,right[i+1]);
            }
            else if(i==n-1){
                min_del = min(min_del,left[i-1]);
            }
            else{
                min_del = min(min_del,left[i-1]+right[i+1]);
            }
            
        }
        return min_del;
    }
};
