class Solution {
public:
    void f(int i,int n,vector<int>& ava,string& temp,string& res,string& pattern)
    {
        if(i==n)
        res=min(res,temp);
        int x=temp.back()-'0';
        if(pattern[i]=='I')
        {
            for(int j=x+1;j<10;j++)
            {
                if(ava[j])
                {
                    ava[j]--;
                    temp.push_back(j+'0');
                    f(i+1,n,ava,temp,res,pattern);
                    temp.pop_back();
                    ava[j]++;
                }
            }
        }
        else
        {
            for(int j=x-1;j>=0;j--)
            {
                if(ava[j])
                {
                    ava[j]--;
                    temp.push_back(j+'0');
                    f(i+1,n,ava,temp,res,pattern);
                    temp.pop_back();
                    ava[j]++;
                }
            }
        }
    }
    string smallestNumber(string pattern) {
        vector<int>ava(10);
        for(int i=1;i<10;i++)
        ava[i]++;
        string temp="";
        string res="999999999999";
        int n=pattern.size();
        for(int i=1;i<10;i++)
        {
            temp.push_back(i+'0');
            ava[i]--;
            f(0,n,ava,temp,res,pattern);
            ava[i]++;
            temp.pop_back();
        }
        return res;
    }
};