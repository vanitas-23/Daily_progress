class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res=0;
        bool b=0;
        int mn=1e9;
        for(auto i:matrix)
        for(auto j:i){
        res+=abs(j);
        mn=min(mn,abs(j));
        if(j<0)
        b=!b;
        }
        return b?res-2*mn:res;
    }
};