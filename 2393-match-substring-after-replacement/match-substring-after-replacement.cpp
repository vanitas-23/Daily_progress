class Solution {
public:
    unordered_map<char, unordered_map<char, char>> isMappingExist;
    bool matching(string s,string t)
    {
        int n=s.size();
        int m=t.size();
        
        for(int i=0;i<n-m+1;i++)
        {
            int curr=0;
            for(int j=0;j<m;j++){
            if(s[i+j]==t[j])
            {
                curr++;
                continue;
            }
            else if(isMappingExist[t[j]][s[i+j]])
            {
                curr++;
                continue;
            }
            else
            break;
            }
            if(curr==m)
            return 1;
        }
        return 0;
    }
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
         for (vector<char> mapping : mappings) {
            isMappingExist[mapping[0]][mapping[1]] = 1;
        }
        return matching(s,sub);
    }
};