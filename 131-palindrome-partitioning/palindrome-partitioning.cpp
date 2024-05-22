class Solution {
public:
    bool isP(string& s,int start,int end)
    {
        while(start<=end)
            if(s[start++]!=s[end--])
            return 0;
        
        return 1;
    }
    void f(int i,int n,string& s,vector<string>& temp,vector<vector<string>>& res)
    {
        if(i==n)
        {
            res.push_back(temp);
            return ;
        }
        for(int id=i;id<n;id++)
        {
            if(isP(s,i,id)){
            temp.push_back(s.substr(i,id-i+1));
            f(id+1,n,s,temp,res);
            temp.pop_back();}
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        int n=s.size();
        vector<string>temp;
        f(0,n,s,temp,res);
        return res;
    }
};