class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        while(x>0 || y>0)
        {
            int lx = x&1;
            int ly = y&1;
            if(lx!=ly)
            {
                count++;
            }
            x=x>>1;
            y=y>>1;
        }
        return count;
    }
};
