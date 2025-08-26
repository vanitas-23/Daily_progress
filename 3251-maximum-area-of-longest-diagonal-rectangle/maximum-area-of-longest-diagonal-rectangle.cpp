class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        int dg=0;
        int ar=0;
        for(auto i:d){
            if(i[0]*i[0]+i[1]*i[1]>dg){
                dg=i[0]*i[0]+i[1]*i[1];
                ar=i[0]*i[1];
            }
            if(i[0]*i[0]+i[1]*i[1]==dg)
                ar=max(ar,i[0]*i[1]);
        }
        return ar;
    }
};