class NumArray {
public:
    // declared globally
    int seg[4*10001];
    int n;
    void build(int ind, int l, int h, vector<int>& nums)
    {
        if(l==h)
        {
            seg[ind] = nums[l];
            return;
        }
        int mid = (l+h)/2;
        build(2*ind+1,l,mid,nums);
        build(2*ind+2,mid+1,h,nums);
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
    int solve(int i,int l,int h,int left,int right)
    {
        if(l>=left && h<=right)
        {
            return seg[i];
        }
        if(l>right || h<left)
        {
            return 0;
        }
        int m = (l+h)/2;
        int val1 = solve(2*i+1,l,m,left,right);
        int val2 = solve(2*i+2,m+1,h,left,right);
        return val1+val2;
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        if(n==0)
        {
            return;
        }
        build(0,0,n-1,nums);
    }
    
    int sumRange(int left, int right) {
        return solve(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
