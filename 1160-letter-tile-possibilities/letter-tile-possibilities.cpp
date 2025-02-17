class Solution {
public:
    set<string>st;
    void f(string s,int mask,string& temp)
    {
        if(temp.size())
        st.insert(temp);
        for(int i=0;i<s.size();i++){
        if(mask&(1<<i)) continue;
        temp+=s[i];f(s,mask|(1<<i),temp);temp.pop_back();
        }
    }
    int numTilePossibilities(string s) {
        string temp="";
        f(s,0,temp);
        return st.size();
    }
};