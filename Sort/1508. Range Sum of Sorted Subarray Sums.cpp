class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>arr;
        arr.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            arr.push_back(arr[i-1]+nums[i]);
        }
        vector<int>res;
        for(int i=0;i<n-1;i++)
        {
            res.push_back(nums[i]);
            if(i==0)
            {
                for(int j=i+1;j<n;j++)
                res.push_back(arr[j]);
            }
            else
            {
                for(int j=i+1;j<n;j++)
                {
                    res.push_back(arr[j]-arr[i-1]);
                }
            }
        }
        res.push_back(nums[n-1]);
        sort(res.begin(),res.end());
        int result = 0;
        for(int i=left-1;i<right;i++)
        {
            result = (result+res[i])%1000000007;
        }
        return result;
    }
};
