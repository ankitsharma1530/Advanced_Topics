class Solution {
public:
    unordered_set<int> prime={2,3,5,7,11,13,17,19,23,29,31};
    int countPrimeSetBits(int L, int R) {
        int count = 0;
        for(int i=L;i<=R;i++)
        {
            int set_bits = 0;
            int ii=i;
            while(ii>0)
            {
                if(ii&1)
                {
                    set_bits++;
                }
                ii=ii>>1;
            }
            if(prime.find(set_bits)!=prime.end())
            {
                count++;
            }
        }
        return count;
    }
};
