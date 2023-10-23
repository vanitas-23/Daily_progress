class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        n/=2;
        int x=accumulate(skill.begin(),skill.end(),0);
        if(x%n!=0)
        return -1;

        x/=n;

        unordered_map<int,int>mp;
        for(int i:skill)
        mp[i]++;
        
        long long ans=0;
        
        for(int i:skill){
        

          //  cout<<i<<" "<<x-i<<" ";
          
            if(mp[x-i]==0){
                return -1;
           }
            ans+=i*1LL*(x-i);
            mp[x-i]--;
           
        }
        return ans/2;
    }
};