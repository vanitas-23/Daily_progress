class Solution {
public:
    int maxDepth(string s) {
        int curr=0;
        int mx=0;
        char res;
        stack<char>st;
        for(char c:s)
        {
            if(st.empty())
            {
                st.push(c);
                if(c!='(')
                res=c;
                else
                curr++;
                mx=max(mx,curr);
            }
            else
            {
                if(c=='(')
                curr++;
                else if(c==')')
                curr--;
                mx=max(curr,mx);
            }
        }
        return mx;
    }
};