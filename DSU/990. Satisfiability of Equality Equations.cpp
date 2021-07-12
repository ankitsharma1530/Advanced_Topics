class Solution {
public:
    char find_par(char node,vector<char>& par){
        if(par[node]==node){
            return node;
        }
        return find_par(par[node],par);
    }
    bool equationsPossible(vector<string>& equations) {
        // union find
        // parent array
        vector<char>par(256);
        for(auto x='a';x<='z';x++){
            par[x] = x;
        }
        for(auto x:equations){
            char a = x[0];
            char b = x[3];
            char par1 = find_par(a,par);
            char par2 = find_par(b,par);
            
            // if you are equal to the become one family
            if(x[1]=='='){
                par[par1] = par2;
            }
            // first build the relation between those characters who are equal to each other 
            // for this you can take the help of example 4
            
        }
        for(auto x:equations){
            char a = x[0];
            char b = x[3];
            char par1 = find_par(a,par);
            char par2 = find_par(b,par);
            if(x[1]=='!'){
                // if it is not equals to 
                // then check if there parents are same return false
                if(par1==par2){
                    return false;
                }
            }
        }
        return true;
    }
};
