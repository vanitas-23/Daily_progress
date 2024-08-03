class Solution {
public:
    int addMinimum(string s) {
        int ans=0;
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                if(s[i]=='b')
                ans++;
                else if(s[i]=='c')
                ans+=2;
                st.push(s[i]);
                continue;
            }
            if(st.top()=='a')
            {
                if(s[i]=='a')
                ans+=2;
                else if(s[i]=='c')
                ans++;
                st.push(s[i]);
            }
            else if(st.top()=='b')
            {
                if(s[i]=='b')
                ans+=2;
                else if(s[i]=='a')
                ans++;
                st.push(s[i]);
            }
            else
            {
                if(s[i]=='c')
                ans+=2;
                else if(s[i]=='b')
                ans++;
                st.push(s[i]);
            }
        }
        if(st.top()=='a')
        ans+=2;
        else if(st.top()=='b')
        ans++;
        return ans;
    }
};