class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res="";
        int curr=0;
        for(int i=0;i<s.size();i++)
        {
            if(curr<spaces.size() && i==spaces[curr])
            res+=" ",curr++;
            res+=s[i];
        }
        return res;
    }
};