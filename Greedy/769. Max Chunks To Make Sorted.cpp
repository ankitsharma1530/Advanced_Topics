class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count = 0;
        int i=0;
        int n=arr.size();
        bool flag = false;
        while(i<n and !flag){
            if(arr[i]==i){
                count++;
                i++;
            }
            else{
                if(arr[i]==n-1){
                    count++;
                    flag=true;
                    i++;
                }
                else{
                    int m = arr[i];
                    while(true){
                        int temp  = INT_MIN;
                        for(int ii=i;ii<=m;ii++){
                            temp = max(temp,arr[ii]);
                        }
                        if(temp==m){
                            break;
                        }
                        m = temp;
                    }
                    i = m+1;
                    count++;
                }
            }
        }
        // cout<<endl;
        return count;
    }
};
