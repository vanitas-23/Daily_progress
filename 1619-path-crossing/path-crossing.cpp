class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>,int>mp;
        int i=0;
        int j=0;
       mp[{i,j}]=1;
        for(char c:path){
           
            if(c=='N')
            i++;
            else if(c=='S')
            i--;
            else if(c=='W')
            j++;
            else
            j--;
             if(mp[{i,j}]!=0)
            return true;
            mp[{i,j}]++;
            cout<<i<<" "<<j<<endl;
        }
        return false;
    }
};