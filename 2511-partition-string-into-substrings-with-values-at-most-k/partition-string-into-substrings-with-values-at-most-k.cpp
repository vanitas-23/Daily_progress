class Solution {
public:
    int minimumPartition(string s, int k) {
        string temp="";
        int cnt=1;
        int n=s.size();
        bool b=0;
        for(int i=0;i<n;i++)
        {
            temp+=s[i];
           // cout<<temp<<endl;
            if(stol(temp)<=k)
            {
                b=1;
                continue;
            }
            else
            {
                cnt++;
                char c=temp.back();
                temp.pop_back();
                temp="";
                temp+=c;
                b=0;
            }
            if(stoi(temp)>k)
            return -1;
        }
        return cnt;
    }
};