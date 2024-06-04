class Solution {
public:
    int bestClosingTime(string s) {
        int n=s.size();
        vector<int>preN(n);
        vector<int>postY(n);
        preN[0]=s[0]=='N';
        postY[n-1]=s[n-1]=='Y';
        for(int i=1;i<n;i++)
        {
            if(s[i]=='N')
            preN[i]=1+preN[i-1];
            else
            preN[i]=preN[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]=='Y')
            postY[i]=1+postY[i+1];
            else
            postY[i]=postY[i+1];
        }
        int curr=1e9;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                if(curr>postY[0])
                {
                    curr=postY[0];
                    ans=0;
                }
                continue;
            }
            if(curr>postY[i]+preN[i-1])
            {
                curr=postY[i]+preN[i-1];
                ans=i;
            }
        }
        if(preN[n-1]<curr)
        ans=n;
        cout<<curr<<" ";
        return ans;
    }
};