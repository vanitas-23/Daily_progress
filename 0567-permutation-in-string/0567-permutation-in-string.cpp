class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>main(26,0);
        for(char c:s1)
        main[c-'a']++;
        vector<int>temp(26,0);
        int n=s2.size();
        int m=s1.size();
        if(m>n)
        return false;
        for(int i=0;i<m;i++)
        temp[s2[i]-'a']++;
        for(int i=m;i<n;i++){
            if(temp==main)
            return true;
            temp[s2[i-m]-'a']--;
            temp[s2[i]-'a']++;
        }
        return temp==main;
    }
};