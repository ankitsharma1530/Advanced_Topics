class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        vector<int>res;
        int x = 0;
        int n = encoded.size();
        for(int i=1;i<=n+1;i++)
        {
            x=x^i;
        }
        // n odd thats why x is also odd
        // x will have 1 at last bit
        int temp = 0;
        for(int i=1;i<n;i=i+2)
        {
            temp=temp^encoded[i];
        }
        res.push_back(x^temp);
        for(int i=1;i<n+1;i++)
        {
            res.push_back(res[i-1]^encoded[i-1]);
        }
        return res;
    }
};
