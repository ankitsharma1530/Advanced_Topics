class NumArray {
public:
    int *segmentTree, *arr, size = 0;
    int buildTree(vector<int>& nums, int start, int end, int node){
        if(start == end){
            return segmentTree[node] = nums[start];
        }
        int mid = (start + end)/2;
        return segmentTree[node] = buildTree(nums, start, mid, 2 * node + 1) + buildTree(nums, mid + 1, end, 2 * node + 2);
    }
    
    NumArray(vector<int>& nums) {
        arr = new int[nums.size()];
        int i = 0;
        size = nums.size();
        for(auto x: nums){
            arr[i] = x;
            i++;
        }
        segmentTree = new int[4 * nums.size() + 1];
        memset(segmentTree, 0, 2 * nums.size() - 1);
        buildTree(nums, 0, nums.size() - 1, 0);
        for(i = 0; i < 2 * nums.size() - 1; i++){
            cout<<segmentTree[i]<<" ";
        }
    }
    
    void updateUtil(int index, int val, int node, int start, int end){
        if(start == end){
            arr[index] = val;
            segmentTree[node] = val;
            return;
        }
        int mid = (start + end)/2;
        if(index <= mid){
            updateUtil(index, val, 2 * node + 1, start, mid);    
        }else{
            updateUtil(index, val, 2 * node + 2, mid + 1, end); 
        }
        segmentTree[node] = segmentTree[2 * node + 1] + segmentTree[2 * node + 2];
    }
    
    void update(int index, int val) {
        updateUtil(index, val, 0, 0, size - 1);
    }
    
    int getSum(int left, int right, int node, int start, int end){
        //complete overlap
        if(right >= end and left <= start){
            return segmentTree[node];
        }
        
        //no overlap
        if(left > end || right < start){
            return 0;
        }
        
        //partial overlap
        int mid = (start + end)/2;
        return getSum(left, right, 2 * node + 1, start, mid) + getSum(left, right, 2 * node + 2, mid + 1, end);
    }
    
    int sumRange(int left, int right) {
        //return 1;
        return getSum(left, right, 0, 0, size - 1);
    }
};
