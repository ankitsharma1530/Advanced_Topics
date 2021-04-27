class Solution {
public:
    int findComplement(int num) {
        int n = 0;
        int temp  = 0;
        while(temp<num)
        {
            temp+=pow(2,n);
            n++;
        }
        return temp^num;
        
    }
};
