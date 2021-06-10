class Solution {
public:
    int search(vector<int>& arr, int target) {
        int i =0;
        int j=arr.size()-1;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(arr[mid]==target){
                return mid;
            }
            if(arr[mid]>arr[j]){
                // 3 4 5 1 2
                if(target<arr[mid] and target>=arr[i]){
                    j=mid-1;
                }
                else{
                    i=mid+1;    
                }
            }
            else if(arr[mid]<arr[i]){
                // 4 5 1 2 3
                if(target>arr[mid] and target<=arr[j]){
                    i=mid+1;
                }
                else{
                    j=mid-1;
                }
            }
            else{
                if(target>arr[mid]){
                    i=mid+1;
                }
                else{
                    j=mid-1;
                }
            }
        }
        return -1;
    }
};
