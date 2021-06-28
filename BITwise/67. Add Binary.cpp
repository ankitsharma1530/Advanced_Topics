class Solution {
public:
    string addBinary(string a, string b) {
        // 1+1 = 10
        // 0+1 = 1
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string res = "";
        int i=0;
        int j=0;
        int carry = 0;
        while(i<a.length() and j<b.length()){
            int num;
            if(a[i]=='1' and b[j]=='1'){
                if(carry==0){
                    num= 10;
                }
                else{
                    num=11;
                }
            }
            else if(a[i]=='1' || b[i]=='1'){
                if(carry==0){
                    num=1;
                }
                else{
                    num = 10;
                }
            }
            else{
                if(carry==0){
                    num=0;
                }
                else{
                    num=1;
                }
            }
            int n1 = num%10;
            carry = num/10;
            res+=to_string(n1);
            i++;
            j++;
        }
        while(i<a.length()){
            int num ;
            if(a[i]=='1'){
                if(carry==1){
                    num = 10;
                }
                else{
                    num=1;
                }
            }
            else{
                if(carry==1){
                    num=1;
                }
                else{
                    num=0;
                }
            }
            int n1= num%10;
            carry = num/10;
            res+=to_string(n1);
            i++;
        }
        while(j<b.length()){
            int num ;
            if(b[j]=='1'){
                if(carry==1){
                    num = 10;
                }
                else{
                    num=1;
                }
            }
            else{
                if(carry==1){
                    num=1;
                }
                else{
                    num=0;
                }
            }
            int n1= num%10;
            carry = num/10;
            res+=to_string(n1);
            j++;
        }
        if(carry==1){
            res+="1";
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
