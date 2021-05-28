class Solution {
public:
    int totalMoney(int n) {
        int sum = 0;
        int times = n/7;
        if(times<1){
            // int sum =0;
            for(int i=1;i<=n;i++){
                sum+=i;
            }
            return sum;
        }
        else{
            
            int x = 0;
            int rem = n%7;
            while(times--){
                for(int i=1+x;i<=7+x;i++){
                    sum+=i;
                }
                x++;
            }
            for(int i=1+x;i<=rem+x;i++){
                sum+=i;
            }
        }
        return sum;
    }
};
