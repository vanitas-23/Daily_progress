class Solution {
public:
    long long minimumCost(string s) {
        long long ans=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]!=s[i+1]){
                if(i+1>s.size()-i-1){
                    ans+=s.size()-i-1;
                }
                else{
                    ans+=i+1;
                }
            }
        }
        return ans;
    }
};