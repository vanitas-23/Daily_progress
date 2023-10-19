

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        remove_letters(s);
        remove_letters(t);
        return s == t;
    }
    void remove_letters(std::string& s){
        auto it = std::find(s.begin(), s.end(), '#');
        while(it != s.end()){
            if(it == s.begin()){
                s.erase(it);
                it = std::find(s.begin(), s.end(), '#');
                continue;
            }
            auto prev = it - 1;
            s.erase(it);
            s.erase(prev);
            it = std::find(s.begin(), s.end(), '#');
        }
    }
};