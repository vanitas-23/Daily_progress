class Solution {
public:
    bool f(int i,int n,string s,int org)
    {
        if(i==n)
        return org==0;
        string curr="";
        bool b=0;
        for(int j=i;j<n;j++)
        {
            curr+=s[j];
            b|=f(j+1,n,s,org-stoi(curr));
        }
        return b;
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int x=i*i;
            string s=to_string(i*i);
            if(f(0,s.size(),s,i))
            {
                // cout<<i<<" ";
                ans+=x;
            }
        }
        return ans;
    }
};