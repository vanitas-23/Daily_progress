class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>frq(26);
        for(char c:s)
        frq[c-'a']++;
        vector<int>res;
        string temp="";
        for(char c:s)
        {
            temp+=c;
            frq[c-'a']--;
            bool b=1;
            for(char l:temp)
            if(frq[l-'a']>0)
            {
                b=0;
                break;
            }
            if(!b)
            continue;
            res.push_back(temp.size());
            temp="";
        }
        return res;
    }
};