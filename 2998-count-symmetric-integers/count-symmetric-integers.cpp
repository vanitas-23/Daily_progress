class Solution {
public:
    bool isSys(int n){
       string s=to_string(n);
        if(s.size()%2)
            return false;
        int ans=0;
        for(int i=0;i<s.size()/2;i++)
            ans+=s[i]-'0';
        for(int i=s.size()/2;i<s.size();i++)
            ans-=s[i]-'0';
        return ans==0;
        
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++)
            if(isSys(i))
                cnt++;
        return cnt;
    }
};