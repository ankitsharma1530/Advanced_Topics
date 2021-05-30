bool isvalid(int mid,vector<int>& nums,int k){
    int c = 1;
    int csum = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>mid){
            return false;
        }
        if(csum+nums[i]>mid){
            c++;
            csum = nums[i];
        }
        else{
            csum+=nums[i];
        }
    }
    if(c>k){
        return false;
    }
    return true;
}
int solve(vector<int>& nums, int k) {
    int i=1;
    int sum = 0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
    }
    int j= sum;
    int ans = INT_MAX;
    while(i<=j){
        int mid = i+(j-i)/2;
        if(isvalid(mid,nums,k)==true){
            j = mid-1;
            ans = min(ans,mid);
        }
        else{
            i=mid+1;
        }
    }
    return ans;
}
