class Solution {
public:
    string replaceWords(vector<string>& dict, string str) {
        istringstream iss(str);
        vector<string> arr;
        string word;
        while (iss >> word) {
        arr.push_back(word);
        }
        string res="";
        set<string> st(begin(dict), end(dict));
        for(auto t:arr)
        {
            int i=0;
            while(i++<t.size())
            {
                string curr = t.substr(0, i);
                if(st.find(curr) != st.end()) {
                    res += curr + " ";
                    break;
            }
            if(i == t.size()) res += curr + " ";
        }
    }
    res.pop_back();
    return res;
    }
};