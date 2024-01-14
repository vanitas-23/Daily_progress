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

std::vector<int> searchKMP(const std::string& s, const std::string& a) {
    std::vector<int> result;
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
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && a[j] != s[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    return result;
}

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>fst= searchKMP(s,a);
        vector<int>scd=searchKMP(s,b);
       // return scd;
        
        vector<int>arr;
        for(int i:fst){
            
          auto  it=lower_bound(scd.begin(),scd.end(),i-k);
            if(it!=scd.end())
                if(abs(*it-i)<=k)
                    arr.push_back(i);
        }
        
        return arr;
    }
};