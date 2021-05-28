int solve(vector<int>& arr) {
    // we will find the index of the smallest element
    int i=0;
    int j=arr.size()-1;
    while(i<j){
        int mid = (i+j)/2;
        if(arr[mid]>arr[j]){
            i=mid+1;
        }
        else{
            j=mid;
        }
    }
    if(i==0){
        return arr[arr.size()-1];
    }
    return arr[i-1];
}
