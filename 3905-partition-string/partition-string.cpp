class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string>st;
        vector<string>arr;
        string curr;
        for(char c:s)
        {
            curr+=c;
            if(st.find(curr)==st.end())
            {
                st.insert(curr);
                arr.push_back(curr);
                curr="";
            }
        }
        return arr;
    }
};