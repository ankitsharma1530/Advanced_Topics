class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // It is evident that the answer lies between [1,n+1]. So bring all the elements              to their respective position
        // what we will do here is, we iterate over the nums, and if the nums[i] is
        // between the range 1--->nums.size() then put it on its correct index
        
        // for exp-> lets suppose our arr[] = {2,3,4,-1}
        // we rearrange the array and put all numbers at their respective index except -ve and zero elements
        // so the array be like => [-1,2,3,4]
        // according to questions condn array should be -> [1,2,3,4]
        
         // so as we can se index 0th is wrong , hence return 1(i+1--->0+1)   
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            // run while loop until we got a -ve or >n number on i
            while(nums[i]>0 and nums[i]<=n and nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
        
    }
};

/*
more example for understanding->
    check leetcode notes.
*/
