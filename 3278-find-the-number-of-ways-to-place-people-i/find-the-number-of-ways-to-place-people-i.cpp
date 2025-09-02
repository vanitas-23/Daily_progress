class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
        int ans=0;
        int n=p.size();
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;   
            if(p[i][0]>p[j][0] || p[i][1]<p[j][1]) continue;
            bool b=1;
            for(int k=0;k<n;k++)
            {
                if(k==i || k==j) continue;
                if(p[k][0]>=p[i][0] && p[k][0]<=p[j][0] && p[k][1]<=p[i][1] && p[k][1]>=p[j][1])
                {
                    b=0;
                    break;
                }
            }
            if(b)
            ans++;
        }
        return ans;
    }
};