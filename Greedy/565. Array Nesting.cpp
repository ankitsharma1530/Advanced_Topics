class Solution {
public:
    // check for leetcode notes for O(1)space solution
    int arrayNesting(vector<int>& nums) {
        vector<bool>vis(nums.size(),false);
        int len = 0;
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                int ans = 1;
                int k = i;
                while(i!=nums[k]){
                    vis[nums[k]]=true;
                    k=nums[k];
                    ans++;    
                }
                len = max(len,ans);
            }
        }
        return len;
    }
};
