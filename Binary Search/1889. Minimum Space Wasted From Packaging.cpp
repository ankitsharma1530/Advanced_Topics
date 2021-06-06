class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        
        // sort
        sort(packages.begin(),packages.end());
        long suma = 0;
        for(int i=0;i<packages.size();i++){
            suma+=packages[i];
        }
        long res = LONG_MAX;
        for(auto& x:boxes){
            sort(x.begin(),x.end());
            // base condn
           // if our maximum box size that supplier gives to us is less than the                      maximum
           // box size that we want , then for that case we just ignore
            if(x[x.size()-1]<packages[packages.size()-1]){
                continue;
            }
            // for each box in box[i] from small to big,
            // find out how many packages in A it can covers,

            // Assume we alreay cover i packages,
            // now we find that we can cover j packages,
            // the space we are using (j - i) * box size.
            // We accumulate the space size.
            long curr= 0;
            long i=0;
            long j;
            
            for(auto& b:x){
                j= upper_bound(packages.begin(),packages.end(),b)-packages.begin();
                // this upper bound is used in place of binary search
                curr+=b*(j-i);
                i=j;
            }
            res = min(res,curr);   
            
        
           
    }
    return res<LONG_MAX? (res-suma)%1000000007 : -1; 
}
                                      };
