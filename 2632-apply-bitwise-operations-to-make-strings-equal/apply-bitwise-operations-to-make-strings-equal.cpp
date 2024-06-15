class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        int o1=count(s.begin(),s.end(),'1');
        int o2=count(t.begin(),t.end(),'1');

        if(o1==0 || o2==0)
        return s==t;
        return 1;
    }
};