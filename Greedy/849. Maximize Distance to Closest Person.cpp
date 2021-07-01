class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int left[n];
        int right[n];
        left[0] = 0;
        right[n-1] =0;
        for(int i=1;i<n;i++){
            if(seats[i]==1){
                left[i]=0;
            }
            else{
                left[i]=left[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(seats[i]==1){
                right[i]=0;
            }
            else{
                right[i]=right[i+1]+1;
            }
        }
        int ans = max(right[0],left[n-1]);
        for(int i=0;i<n;i++){
            int t = min(left[i],right[i]);
            ans = max(t,ans);
        }
        return ans;
    }
};
