class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
        vector<int>perm(n+1,0);
        int i=0,j=n,x=0;
        (s[0]=='I')?(perm[0]=i++):(perm[0]=j--);

        for(int k=1; k<n; k++){
            (s[k]=='I')?(perm[k]=i++):(perm[k]=j--);
        }
        (s[n-1]=='I')?(perm[n]=i++):(perm[n]=j--);
        return perm;
    }
};