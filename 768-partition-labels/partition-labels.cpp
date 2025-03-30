class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int>lst(26);
        vector<int>ans;
        for(int i=0;i<n;i++)
        lst[s[i]-'a']=i;
        int mx=-1;
        int f=-1;
        for(int i=0;i<n;i++)
        {
           mx=max(mx,lst[s[i]-'a']);
           if(mx==i)
           ans.push_back(i-f),f=i;
        }
        return ans;
    }
};