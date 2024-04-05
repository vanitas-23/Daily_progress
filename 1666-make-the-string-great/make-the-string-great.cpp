class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(char c:s){
            if(st.empty())
            st.push(c);
            else if(abs(st.top()-c)==32)
            st.pop();
            else
            st.push(c);
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