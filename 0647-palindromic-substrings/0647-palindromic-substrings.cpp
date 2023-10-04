class Solution {
public:
    bool is(string s){
        string r=s;
        reverse(r.begin(),r.end());
        return r==s;
    }
    int countSubstrings(string s) {
        int cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            cnt++;
            string res="";
            res+=s[i];
            for(int j=i+1;j<n;j++){
                res+=s[j];
                if(is(res))
                cnt++;
            }
        }
        return cnt;
    }
};