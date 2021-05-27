int solve(vector<int>& nums) {
    int i=0;
    if(nums.size()==0){
        return -1;
    }
    int j=nums.size()-1;
    int ans = INT_MAX;
    while(i<j){
        int mid =  i+(j-i)/2;
        if(mid<=nums[mid]){
            j=mid;

        }
        else{
            i=mid+1;
        }
    }
    if(nums[j]==j){
        return i;
    }
    return -1;
}
