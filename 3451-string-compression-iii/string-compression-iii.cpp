class Solution {
public:
    string compressedString(string word) {
        stack<pair<char,int>>st;
        for(char c:word)
        {
            if(st.empty())
            {
                st.push({c,1});
                continue;
            }
            if(c==st.top().first && st.top().second<9)
            {
                auto x=st.top();
                st.pop();
                st.push({c,x.second+1});
            }
            else
                st.push({c,1});
        }
        string res="";
        while(!st.empty())
        {
            auto x=st.top();
            st.pop();
            res+=x.first;
            res+=(x.second+'0');
            
        }
        reverse(res.begin(),res.end());
        return res;
    }
};