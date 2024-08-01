class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(auto s:details)
        {
            auto x=stoi(s.substr(11,2));
            if(x>60)
            ans++;
        }
        return ans;
    }
};