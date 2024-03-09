class Solution {
public:
    
    unordered_map<string,int>memo;
    
    int kSimilarity(string s1, string s2,int pos=0) {
        
        if(s1==s2)
        {
            return 0;
        }
        
        if(memo.count(s1))
        {
            return memo[s1];
        }
        
        while(pos<s1.length() && s1[pos]==s2[pos]){
            pos++;
        }
        int ans=99999999;
        
        for(int i=pos+1;i<s1.length();i++)
        {
            if(s1[i]!=s2[i] && s1[i]==s2[pos])
            {
                swap(s1[pos],s1[i]);
                ans=min(ans,kSimilarity(s1,s2,pos+1)+1);
                swap(s1[pos],s1[i]);
            }
        }
        
        return memo[s1]=ans;
    }
};