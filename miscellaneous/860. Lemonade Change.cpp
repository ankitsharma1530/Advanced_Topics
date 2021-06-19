class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>ump;
        for(auto x:bills){
            ump[x]++;
            int rem = x-5;
            if(rem!=0){
                if(rem==15){
                    if((ump[10]>0 and ump[5]>0)){
                        ump[10]--;
                        ump[5]--;
                    
                    }
                    else if((ump[5]>2)){
                        ump[5]-=3;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    if(ump[5]>0){
                        ump[5]--;
                    }
                    else{
                        return false;
                    }
                }
                
            }
        }
        return true;
    }
};
