class Solution {
public:
    bool isSubsequence(string s, string t) {
       int i=0;
       int j=0;
       int cnt=0;
       while(j<t.size()){
           if(s[i]==t[j])
           {
               cnt++;
               i++;
           }
           j++;
       }
       return cnt==s.size()?true:false;
    }
};