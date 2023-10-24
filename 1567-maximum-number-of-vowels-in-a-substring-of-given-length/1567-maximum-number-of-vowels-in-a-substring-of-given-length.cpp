class Solution {
public:
  
    bool isV(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        return 1;
        return 0;
    }
    int maxVowels(string s, int k) {
        int n=s.size();
        int no=0;
        for(int i=0;i<k;i++)
        if(isV(s[i]))
        no++;

        int ans=no;
        for(int i=k;i<n;i++){
            if(isV(s[i]))
            no++;
            if(isV(s[i-k]))
            no--;

            ans=max(ans,no);
        }
        return ans;
    }
};