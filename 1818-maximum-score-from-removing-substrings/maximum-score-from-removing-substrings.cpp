class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n=s.size();
        int ans=0;
        stack<char>st;

        for(char c:s)
        {
            if(st.empty())
            {
                st.push(c);
                continue;
            }
            if(x>y)
            {
                if(st.top()=='a' && c=='b')
                ans+=x,st.pop();
                else
                st.push(c);
            }
            else
            {
                if(st.top()=='b' && c=='a')
                ans+=y,st.pop();
                else
                st.push(c);
            }
        }
        string t="";
        while(!st.empty())
        {
            t+=st.top();
            st.pop();
        }
        reverse(t.begin(),t.end());
        for(char c:t)
        {
            if(st.empty())
            {
                st.push(c);
                continue;
            }
            if(st.top()=='a' && c=='b')
            ans+=x,st.pop();
            else if(st.top()=='b' && c=='a')
            ans+=y,st.pop();
            else
            st.push(c);
        }
        return ans;
    }
};