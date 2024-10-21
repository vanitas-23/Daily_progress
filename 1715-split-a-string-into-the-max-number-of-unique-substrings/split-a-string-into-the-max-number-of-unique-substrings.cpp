class Solution {
public:
    int f(int i,int n,string s,unordered_set<string>& st)
    {
        if(i==n)
        return 0;
        string temp="";
        int ans=0;
        for(int j=i;j<n;j++)
        {
            temp+=s[j];
            if(st.find(temp)==st.end())
            {
                st.insert(temp);
                ans=max(ans,1+f(j+1,n,s,st));
                st.erase(temp);
            }
        }
        return ans;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        int n=s.size();
        return f(0,n,s,st);
    }
};