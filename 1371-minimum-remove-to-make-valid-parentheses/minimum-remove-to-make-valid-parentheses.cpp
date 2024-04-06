class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        vector<int>arr(s.size());
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=')' && s[i]!='(')
            continue;
            if(st.empty()){
            st.push({s[i],i});
            continue;
            }
            if(st.top().first=='(' && s[i]==')')
            st.pop();
            else
            st.push({s[i],i});
        }
        while(!st.empty()){
           // cout<<st.top().first<<" ";
        arr[st.top().second]=1,st.pop();
        }
        string res="";
        for(int i=0;i<s.size();i++)
        if(arr[i]==0)
        res+=s[i];
        return res;
    }
};