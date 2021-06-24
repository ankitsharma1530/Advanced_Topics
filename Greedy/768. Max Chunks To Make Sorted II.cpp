class Solution {
public:
    // time complexity -> O(n)
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int left[n+1];
        int right[n+1];
        left[0] = arr[0];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],arr[i]);
        }
        right[n] = INT_MAX;
        for(int i=n-1;i>=0;i--){
            right[i] = min(right[i+1],arr[i]);
        }
        int chunks = 0;
        for(int i=0;i<n;i++){
            // whenever the left maximum is less than or equal to right minimum
            // that is the case for our chunk
            if(left[i]<=right[i+1]){
                chunks++;
            }
        }
        return chunks;
    }
};
