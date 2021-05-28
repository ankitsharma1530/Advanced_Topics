bool isvalid(int mid, vector<int>&piles, int k){
    int time = 0;
    for(int i=0;i<piles.size();i++){
        time+=ceil((double)piles[i]/mid);
    }
    if(time<=k){
        return true;
    }
    return false;
}
int solve(vector<int>& piles, int k) {
    if(piles.size()==1){
        int num = ceil((double)piles[0]/k);
        // cout<<piles[0];
        return num;
    }
    int i = 1;
    int j = *max_element(piles.begin(),piles.end());
    int ans = -1;
    while(i<=j){
        int mid = i+(j-i)/2;
        if(isvalid(mid,piles,k)==true){
            ans = mid;
            j=mid-1;
        }
        else{
            i=mid+1;
        }
    }
    return ans;
}
