class Solution {
public:
    int minimumRecolors(string b, int k) {
        int ans=0;
        string temp="";
        for(int i=0;i<k;i++)
        {
            temp+=b[i];
            if(b[i]=='W')
            ans++;
        }
        int n=b.size();
        int t=ans;
        for(int i=k;i<n;i++)
        {
            if(temp[0]=='W')
            t--;
            if(b[i]=='W')
            t++;
            ans=min(ans,t);
            temp+=b[i];
            temp.erase(0,1);
        }
        return ans;
    }
};