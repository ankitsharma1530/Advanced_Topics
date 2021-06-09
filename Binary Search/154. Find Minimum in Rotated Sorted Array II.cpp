class Solution {
public:
    int findMin(vector<int>& arr) {
        
        int i=0;
        int j=arr.size()-1;
        while(i<j){
            int mid = i+(j-i)/2;
            if(arr[mid]>arr[j]){
                // ......4 5 1 2
                // middle element is 4
                // and as 4>2 hence it states that the answer will be in the right
                i=mid+1;
            }
            else if(arr[mid]<arr[j]){
                j=mid;
            }
            else{
                j--;
            }
        }
        return arr[j];
    }
};
