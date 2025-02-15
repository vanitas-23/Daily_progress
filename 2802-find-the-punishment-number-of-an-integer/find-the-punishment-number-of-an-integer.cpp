class Solution {
public:
    bool f(int i,string& s ,int n)
    {
        if(i==s.size())
        return n==0;
        string temp="";
        bool b=0;
        for(int j=i;j<s.size();j++)
        {
            temp+=s[j];
            int x=stoi(temp);
            if(x>n)
            break;
            b|=f(j+1,s,n-x);
        }
        return b;
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int x = i*i;
            string s=to_string(x);
            if(f(0,s,i))
            ans+=x;
        }
        return ans;
    }
};