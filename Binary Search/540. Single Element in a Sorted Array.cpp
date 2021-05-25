class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int i =0;
        int j=arr.size()-1;
        int ans = -1;
        while(i<j)
        {
            int mid = (i+j)/2;
            if((mid%2==0 and arr[mid]==arr[mid+1]) || (mid%2!=0 and arr[mid]==arr[mid-1])){
                
            // ans = i;
            i = mid+1;
            }
            else{
                j=mid;
            }
        }
        return arr[i];
        
    }
};
