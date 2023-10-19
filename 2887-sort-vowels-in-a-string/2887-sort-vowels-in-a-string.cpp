class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
    string sortVowels(string s) {
        
        vector<int>loc;
        vector<char>ele;
        
        for(int i=0;i<s.size();i++)
        if(isVowel(s[i])){
            ele.push_back(s[i]);
            loc.push_back(i);
        }
        sort(ele.begin(),ele.end());
        for(int i=0;i<loc.size();i++)
        s[loc[i]]=ele[i];

        return s;
    }
};