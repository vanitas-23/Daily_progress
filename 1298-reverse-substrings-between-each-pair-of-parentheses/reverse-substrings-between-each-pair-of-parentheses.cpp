class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        for(char c:s)
        {
            if(st.empty())
            st.push(c);
            else
            {
                if(c!=')')
                {
                    st.push(c);
                    continue;
                }
                string t="";
                while(st.top()!='(')
                {
                    t+=st.top();
                    st.pop();
                }
                st.pop();
                for(char x:t)
                st.push(x);
            }
        }
        string res="";
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};