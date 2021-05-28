class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        while(true){
            bool iszero = true;
            int c_odd = 0; 
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=0){
                    iszero = false;
                    
                }
                if(nums[i]&1){
                    nums[i]-=1;
                    c_odd++;
                }
            }
            if(iszero){
                break;
            }
            if(c_odd==0){
                for(int i=0;i<nums.size();i++){
                    nums[i]=nums[i]/2;
                }
                count++;
            }
            count+=c_odd;
        }
        return count;
    }
};
