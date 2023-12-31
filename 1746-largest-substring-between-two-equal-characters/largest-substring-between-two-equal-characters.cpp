class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<vector<int>> v(26,vector<int>(2,-1));
        for(int i=0;i<s.size();i++){
            if(v[s[i]-'a'][0]==-1){
                v[s[i]-'a'][0]=i;
            }
        }
        for(int i=s.size()-1;i>=0;i--){
            if(v[s[i]-'a'][1]==-1){
                v[s[i]-'a'][1]=i;
            }
        }
        int mx=-1;
        for(int i=0;i<26;i++){
            if(v[i][1]!=-1 && v[i][0]!=-1){
            mx=max(mx,v[i][1]-v[i][0]-1);}
        }
        return mx;
    }
};