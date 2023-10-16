class Solution {
public:
    vector<int> f(vector<int>res ,int i,int r){
        if(i==r)
        return res;
        int n=res.size();
        vector<int>dum(n+1);
        dum[0]=res[0];
        dum[n]=res[n-1];
        for(int i=1;i<n;i++)
        dum[i]=res[i-1]+res[i];        
        return f(dum,i+1,r);
    }
    vector<int> getRow(int r) {
        return f({1},0,r);
    }
};