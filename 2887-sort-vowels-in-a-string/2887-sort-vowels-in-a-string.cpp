class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char>st;
        vector<int>loc;
        vector<char>ele;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');
        for(int i=0;i<s.size();i++)
        if(st.find(s[i])!=st.end()){
            ele.push_back(s[i]);
            loc.push_back(i);
        }
        sort(ele.begin(),ele.end());
        for(int i=0;i<loc.size();i++)
        s[loc[i]]=ele[i];

        return s;
    }
};