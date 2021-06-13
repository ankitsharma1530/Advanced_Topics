class Solution {
public:
    // there is a formula for this game
    // if we have all distinct numbers and we had to find what will be the sum of
    // all diagonals and all rows with all columns then the formula is
    // int num = (n^2-n)/2 + 1
    // after getting this num add n consicutive numbers from num-->to--->num+n
    
    // exp => n = 3,    int num = (9-3)/2+1 = 4
    // hence ans = 4+5+6 = 15
    
    
    bool check(vector<vector<int>>& grid,int i,int j){
        unordered_set<int>st;
        for(int ii=i;ii<i+3;ii++){
            for(int jj=j;jj<j+3;jj++){
                if(grid[ii][jj]==0){
                    return false;
                }
                if(st.find(grid[ii][jj])!=st.end()){
                    return false;
                }
                st.insert(grid[ii][jj]);
            }
        }
        if(grid[i][j]+grid[i][j+1]+grid[i][j+2]!=15 ){
            return false;
        }
        if(grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2]!=15){
            return false;
        }
        if(grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2]!=15){
            return false;
        }
        if(grid[i][j]+grid[i+1][j]+grid[i+2][j]!=15){
            return false;
        }
        if(grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1]!=15){
            return false;
        }
        if(grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2]!=15){
            return false;
        }
        if(grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2]!=15){
            return false;
        }
        if(grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j]!=15){
            return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n<3 || m<3){
            return 0;
        }
        
        int count = 0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                if(check(grid,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};
