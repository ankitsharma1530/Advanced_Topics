class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // we will treat this sorted matrix as a sorted list
        
        // the list size will be n*m-1
        // after treating this sorted list we can simply use binary search to find 
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0;
        int j=n*m-1;
        if(matrix.size()==0)
        {
            return false;
        }
        while(i<=j){
            int mid = i+(j-i)/2;
            if(matrix[mid/m][mid%m]==target){
                return true;
            }
            // take example for matrix[1][1] = 11
            // here for this mid -> 5
            // hence row = 5/4 = 1
            // and column = 5%4 = 1
            if(matrix[mid/m][mid%m]<target){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return false;
        // time complexity -> O(log(m*n))
    }
};
