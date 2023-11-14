class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> st;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(st.find(s[i])!=st.end())
            continue;
            st.insert(s[i]);
            
            int k=-1;
            for(int x=i+1;x<s.size();x++)
            if(s[x]==s[i])
            k=x;

            unordered_set<char>sp;
            for(int x=i+1;x<k;x++)
            sp.insert(s[x]);
            ans+=sp.size();
        }
        return ans;
    }
};

