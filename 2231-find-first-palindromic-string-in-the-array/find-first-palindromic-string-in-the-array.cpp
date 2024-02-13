class Solution {
public:
    bool isP(string s)
    {
        string t=s;
        reverse(t.begin(),t.end());
        return t==s;
    }
    string firstPalindrome(vector<string>& words) {
        
        for(auto i:words)
        if(isP(i))
        return i;
        return "";
    }
};