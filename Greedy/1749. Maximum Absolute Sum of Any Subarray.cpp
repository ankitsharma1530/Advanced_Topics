class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int res = nums[0];
        int curr_sum = nums[0];
        int res2 = nums[0];
        int neg_sum = nums[0];
        for(int i=1;i<nums.size();i++){
            if(curr_sum<0){
                curr_sum = 0;
            }
            if(neg_sum>0){
                neg_sum = 0;
            }
            neg_sum +=nums[i];
            curr_sum +=nums[i];
            
            res = max(res,(curr_sum));
            res2 = min(res2,neg_sum);
        }
        return max(res,abs(res2));
    }
};

/*
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = INT_MIN, mini = INT_MAX;
        int sum1=0,sum2=0;
        for(int i=0;i<nums.size();i++){
            sum1+=nums[i];
            sum2+=nums[i];
            if(sum1<0)  sum1 = 0;
            if(sum2>0)  sum2 = 0;
            maxi = max(maxi,sum1);
            mini = min(mini,sum2);
            
        }
        return max(abs(maxi),abs(mini));
    }
};

*/
