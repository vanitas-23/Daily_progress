class Solution {
public:
    std::vector<int> computeLPS(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> lps(m, 0);
    
    int len = 0;
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    return lps;
}

bool searchKMP(const std::string& s, const std::string& a) {
   // std::vector<int> result;
    int n = s.length();
    int m = a.length();
    std::vector<int> lps = computeLPS(a);
    
    int i = 0;
    int j = 0;
    
    while (i < n) {
        if (a[j] == s[i]) {
            j++;
            i++;
        }
        
        if (j == m) {
            return 1;
           // result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && a[j] != s[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    return 0;
}
    int repeatedStringMatch(string a, string b) {
        if(a == b){
            return 1;
        }

        string st = a;
        int repeat = 1;

        while(st.length()<b.length()){
            st += a;
            repeat++;
        }

        if(searchKMP(st,b)==true){
            return repeat;
        }
    
        if(searchKMP(st+a,b)==true){
            return repeat+1;
        }
        else{
            return -1;
        }


    }
};