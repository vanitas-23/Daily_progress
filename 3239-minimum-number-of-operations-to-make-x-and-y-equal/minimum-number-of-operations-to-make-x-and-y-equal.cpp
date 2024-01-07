class Solution {
public:
    int minimumOperationsToMakeEqual(int xt, int y) {
        unordered_map<int,int>mp;
        
        queue<pair<int,int>>q;
        
        q.push({xt,0});
        
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int a=x.first;
            int b=x.second;
            if(a==y)
                return b;
            
            
            if(mp.find(a+1)==mp.end()){
                q.push({a+1,b+1});
                mp[a+1]=1;
            }
            if(a<y)
                continue;
            
            if(mp.find(a-1)==mp.end()){
                q.push({a-1,b+1});
                mp[a-1]=1;
            }
            if(a%11==0 && mp.find(a/11)==mp.end()){
                q.push({a/11,b+1});
                mp[a/11]=1;
            }
             if(a%5 ==0 && mp.find(a/5)==mp.end()){
                 q.push({a/5,b+1});
                 mp[a/5]=1;}
        }
        return abs(xt-y);
    }
};