/* The functions which 
builds the segment tree */
int s[4*1001];
void build(int arr[], int ind , int l , int h)
{
    if(l==h)
    {
        s[ind] = arr[l];
        return;
    }
    int mid = (l+h)/2;
    build(arr,2*ind+1,l,mid);
    build(arr,2*ind+2,mid+1,h);
    s[ind] = min(s[2*ind+1],s[2*ind+2]);
}
int *constructST(int arr[],int n)
{
  //Your code here
  build(arr,0,0,n-1);
  return s;
}


/* The functions returns the
 min element in the range
 from a and b */
 int solve(int i, int l, int h, int a, int b, int st[])
 {
     // l and h are the range of segment
     // lies inside the range
     if(l>=a && h<=b)
     {
         return st[i];
     }
     if(h<a || l>b)
     {
         return INT_MAX;
     }
     int m = (l+h)/2;
     int left = solve(2*i+1,l,m,a,b,st);
     int right = solve(2*i+2,m+1,h,a,b,st);
     return min(left,right);
 }
int RMQ(int st[] , int n, int a, int b)
{
//Your code here
    return solve(0,0,n-1,a,b,st);
}
