class Solution {
public:
    int f(vector<int>& tops, vector<int>& bts,int curr)
    {
        int n=tops.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(tops[i]==curr) continue;
            if(bts[i]!=curr)
            return 1e9;
            ans++;
        }
        return ans;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bts) {
        int ans=1e9;
        for(int i=1;i<=6;i++)
        ans=min({ans,f(tops,bts,i),f(bts,tops,i)});
        
        return ans==1e9?-1:ans;
    }
};