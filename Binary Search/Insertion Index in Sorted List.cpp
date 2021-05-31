int solve(vector<int>& nums, int target) {
    int i=0;
    int j=nums.size()-1;
    while(i<j){
        int mid = i+(j-i)/2;
        if(nums[mid]<=target){
            i=mid+1;
        }
        else{
            j=mid;
        }
    }
    if(j==nums.size()-1){
        if(target>=nums[j]){
            return nums.size();
        }
    }
    return j;
}
