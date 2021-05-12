class Solution {
public:
    int find(vector<int>& arr, int largest_num)
    {
        // int res = -1;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==largest_num)
            {
                return i;
            }
        }
        return -1;
    }
    void flip(vector<int>& arr, int index)
    {
        int i=0;
        int j=index;
        while(i<j)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int>res;
        int n = arr.size();
        int largest_num = n;
        for(int i=0;i<n;i++)
        {
            // find the ind of maximum element
            int ind = find(arr,largest_num);
            // then we have to flip the array twice
            flip(arr,ind);
            flip(arr,largest_num-1);
            res.push_back(ind+1);
            res.push_back(largest_num);
            largest_num--;
        }
        return res;
    }
};
