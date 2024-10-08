class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(char c:s)
        {
            if(st.empty())
            st.push(c);
            else
            {
                if(c==']' && st.top()=='[')
                st.pop();
                else
                st.push(c);
            }
        }
        int x=st.size();
        x/=2;
        return ceil(x*1.0/2);
    }
};