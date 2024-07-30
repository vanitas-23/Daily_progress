class Solution {
public:
    int f(string s,int a,int b)
    {
        stack<int>st;
        int cnt=0;
        for(char c:s)
        {
            if(st.empty())
            {
                st.push(c-'a');
                continue;
            }
            if(!st.empty() && st.top()==b && (c-'a')==a)
            st.pop(),cnt++;
            else
            st.push(c-'a');
        }
        return cnt;
    }
    int minimumDeletions(string s) {
        string t=s;
        reverse(s.begin(),s.end());
        return min(f(t,0,1),f(s,1,0));
    }
};