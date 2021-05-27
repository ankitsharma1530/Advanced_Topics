int solve(int n) {
    long long i = 1;
    long long j = n/2;
    int ans = -1;
    while(i<j){
        long long mid = i+(j-i)/2;
        if(mid*mid==n){
            return mid;
        }
        if(mid*mid<n){
            ans = mid;
            i = mid+1;
        }
        else{
            j = mid;
        }
    }
    return ans;
}
