class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int>v(n+1,0);
        v[1] = 1; // as 1 is not a prime number
        for(int i=2;i<=n;i++){
            if(v[i]==0){
                v[i]=i;
                for(int j=i*i;j<=n;j+=i){
                    if(v[j]==0){
                        v[j]=i;
                    }
                }
            }
        }
        return v;
    }
};
