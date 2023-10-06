class Solution {
public:
    int solve(vector<int>&v,int i,vector<int>&a){
        if(i==v.size()){
            int ans=0;
            for(auto it : a)ans=max(ans,it);
            return ans;
        }
        int minn=INT_MAX;
        for(int j=0;j<a.size();j++){
            a[j]+=v[i];
            minn=min(minn,solve(v,i+1,a));
            a[j]-=v[i];
        }
        return minn;
    }
    int distributeCookies(vector<int>&v, int k) {
        int n=v.size();
        vector<int>a(k);
        return solve(v,0,a);}
};