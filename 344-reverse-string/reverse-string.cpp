class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size()==0)
            return ;
        char c=s.back();
        s.pop_back();
        reverseString(s);
        s.insert(s.begin(),c);
    }
};