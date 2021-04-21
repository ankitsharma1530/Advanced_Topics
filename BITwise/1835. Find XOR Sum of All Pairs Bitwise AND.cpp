

// 
// Intution:
// Simple logic is count number of set Bits for every bit position [0,31] for every element present in arr1 and arr2 in respective ones1 and second1 arrays of size [0,31].
// To make pair the best logic is to make a cross product of the counters obtained.
// If this Cross product is odd add that contribution of the bit position (1<<position) to the ans.



typedef long long ll;

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        
        vector<ll>ones1(32,0);
        vector<ll>second1(32,0);
        
        for(auto ele:arr1){
            int times=0;
            while(times<32){
                
                if((ele&(1<<times))!=0){
                    ones1[times]++;
                }
                times++;
            }
        }
        
        for(auto ele:arr2){
            int times=0;
            while(times<32){
                
                if((ele&(1<<times))!=0){
                    second1[times]++;
                }
                times++;
            }
        }
        
        int i=0;
        ll ans=0;
        while(i<32){
            if(ones1[i]*second1[i]%2!=0){
                ans+=(1<<i);
            }
            
            i++;
        }
        return ans;
        

    }
};
