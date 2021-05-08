class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int,int> > mp;
        for(auto p:points){
            mp.insert({p[0],p[1]});
        }
        int area=INT_MAX;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                if(i!=j){
                    if(points[i][0]!=points[j][0] && points[i][1]!=points[j][1]){
                        pair<int,int> op1={points[i][0],points[j][1]};
                        pair<int,int> op2={points[j][0],points[i][1]};
                        if(mp.count(op1) && mp.count(op2)){
                            int l=abs(points[i][0]-points[j][0]),w=abs(points[i][1]-points[j][1]);
                            area=min(area,l*w);
                        }
                    }
                }
            }
        }
        return area==INT_MAX ? 0 : area;
    }
};
