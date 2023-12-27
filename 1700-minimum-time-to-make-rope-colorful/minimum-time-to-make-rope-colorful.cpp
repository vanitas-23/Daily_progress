class Solution {
public:
    int minCost(string s, vector<int>& t) {
     stack<char>st;
     int ans=0;
     for(int i=0;i<t.size();i++)   {
         if(st.empty()){
             st.push(s[i]);
             continue;
         }
         if(s[i]==st.top()){
         ans+=min(t[i-1],t[i]);
         t[i]=max(t[i],t[i-1]);}
         st.push(s[i]);
     }
     return ans;
    }
};