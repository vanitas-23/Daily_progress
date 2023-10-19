class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string st="";
        string rt="";
        for(char c:s){
            if(c=='#'){
                if(st.size()>0)
                st.pop_back();
                continue;
            }
            st+=c;
        }
        for(char c:t){
            if(c=='#'){
                if(rt.size()>0)
                rt.pop_back();
                continue;
            }
            rt+=c;
        }
        return st==rt;
    }
};