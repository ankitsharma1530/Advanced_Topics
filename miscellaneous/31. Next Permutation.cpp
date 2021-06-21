class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k,  l;
        for(k=n-2;k>=0;k--)
        {
            // first we had to find a position where the sorting violates
            if(nums[k]<nums[k+1])
            {
                break;
            }
        }
        // if k < 0 this means array is sorted 
        // eg -> [3,2,1] as this is sorted already hence k<0
        // next permutation is [1,2,3] i.e reverse(arr.begin(),arr.end())
        if(k<0)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            // we will find a number that is greater than the break point
            for(l=n-1;l>k;l--)
            {
                if(nums[l]>nums[k])
                {
                    break;
                }
            }
            swap(nums[l],nums[k]);
            reverse(nums.begin()+k+1,nums.end());
        }
    }
};
