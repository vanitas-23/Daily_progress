#define ll long long
class Solution {
public:
    bool f(string s,int mid,vector<int>& order,ll k,int n)
    {
        for(int i=0;i<mid && i<n ;i++)
        s[order[i]]='*';
        int left=0;
        int right=n-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='*')
            {
                k-=(left+1)*1ll*(right+1);
                left=0;
                if(k<=0)
                return 1;
            }
            else
            {
                left++;
            }
            right--;
        }
        return 0;
    }
    int minTime(string s, vector<int>& order, int k) {
        int n=s.size();
        int l=1;
        int r=n;
        int ans=n+1;
        while(l<=r)
        {
            int mid=(r-(r-l)/2);
            if(f(s,mid,order,k,n))
            {
                ans=mid;
                r=mid-1;
            }
            else
            l=mid+1;
        }
        f(s,2,order,k,n);
        return ans==(n+1)?-1:ans-1;
    }
};