class Solution {
public:
    bool isvalid(int mid, vector<int>&nums , int m){
        int c = 0;
        for(int i=0;i<nums.size();i++){
            c+=(nums[i]/mid);
            if(nums[i]%mid==0){
                c--;
            }
        }
        if(c>m){
            return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int m) {
        int i=1;
        int j = *max_element(nums.begin(),nums.end());
        int res = 0;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(isvalid(mid,nums,m)){
                res = mid;
                j = mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return res;
    }
};
