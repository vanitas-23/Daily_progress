class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int,int>>st;
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push({s[i],1});
                continue;
            }
            if(st.top().first==s[i])
            cnt=st.top().second+1;
            else
            cnt=1;

            st.push({s[i],cnt});
            if(cnt==k)
            {
                for(int j=0;j<k;j++)
                st.pop();
            }
        }
        string t="";
        while(!st.empty())
        {
            t+=st.top().first;
            st.pop();
        }
        reverse(t.begin(),t.end());
        return t;
    }
};