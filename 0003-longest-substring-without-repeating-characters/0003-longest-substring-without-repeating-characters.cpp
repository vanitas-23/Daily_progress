class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int n=s.size();
        int ans=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(st.find(s[i])==st.end()){
                st.insert(s[i]);
                ans=max(ans,i-j+1);
            }
            else{
                while(st.find(s[i])!=st.end()){
                st.erase(s[j]);j++;}
                st.insert(s[i]);
                ans=max(ans,i-j+1);
            }
        }
        return ans;
    }
};