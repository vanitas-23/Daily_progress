class Solution {
public:
    int maximumLength(string s) {
        vector<vector<int>>req(26);

        int n=s.size();
        int i=0;
        int j=1;
        while(j<n){
            if(s[j-1]!=s[j]){
            req[s[j-1]-'a'].push_back(j-i);
            i=j;
        }
        j++;
    }
    req[s[j-1]-'a'].push_back(j-i);
    int mx=-1;

    for(int i=0;i<26;i++){
        if(req[i].size()>=3)
        {

        sort(req[i].begin(),req[i].end());

        mx=max(mx,req[i][req[i].size()-3]);
        mx=max(mx,req[i][req[i].size()-1]-2);
        if(req[i][req[i].size()-1]==req[i][req[i].size()-2])
        mx=max(mx,req[i][req[i].size()-1]-1);
        }
        else if(req[i].size()==2)
        {
            
            int sb=max(req[i][0],req[i][1]);
            if(req[i][0]+req[i][1]<3)
            continue;
            if(req[i][0]==req[i][1]){
                mx=max(mx,req[i][0]-1);
                continue;
            }
            sb-=2;

            sb=max(sb,min(req[i][0],req[i][1]));
            mx=max(mx,sb);
        }
        else if(req[i].size()==1)
        mx=max(mx,req[i][0]-2);
    }
    return mx==0?-1:mx;
    }
};