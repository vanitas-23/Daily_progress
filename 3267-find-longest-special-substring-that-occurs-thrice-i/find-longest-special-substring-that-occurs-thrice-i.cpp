class Solution {
public:
    bool isg(string s){
        unordered_map<int,int>z;
        for(char c:s)
            z[c-'a']++;
        return z.size()==1;
    }
    int maximumLength(string s) {
        int n=s.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)
            for(int j=n-1;j>i;j--){
                string str=s.substr(i,j-i+1);
                //cout<<str<<endl;
                if(isg(str))
                mp[str]++;
            }
        int x=-1;
        for(auto i:mp)
            if(i.second>=3)
                x=max(x,(int)i.first.size());
        unordered_map<int,int>sp;
        for(char c:s)
            sp[c-'a']++;
        for(auto i:sp)
            if(i.second>=3)
                x=max(x,1);
        return x;
    }
};