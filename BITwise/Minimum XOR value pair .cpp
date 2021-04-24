class Solution{
public:
int minxorpair(int n, int arr[]){
//code here
sort(arr,arr+n);
int min=10000;
for(int i=0;i<n-1;i++) 
{
    int p=arr[i]^arr[i+1]; 
    if(min>p)
        min=p;
}
return min;
}
};
