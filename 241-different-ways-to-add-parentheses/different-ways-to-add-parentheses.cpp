class Solution {
public:
    vector<int> f(int i,int n,string exp)
    {
        if(i==n-1)
        return {exp[i]-'0'};
        vector<int>arr;
        bool op=0;
        for(int j=i;j<n;j++)
        {
            if(exp[j]=='+' || exp[j]=='-' || exp[j]=='*')
            {
                op=1;
                auto x=f(i,j,exp);
                auto y=f(j+1,n,exp);
                for(auto l:x)
                for(auto r:y)
                {
                    if(exp[j]=='+')
                    arr.push_back(l+r);
                    else if(exp[j]=='-')
                    arr.push_back(l-r);
                    else
                    arr.push_back(l*r);
                }
            }
        }
        if(op==0)
        arr.push_back(stoi(exp.substr(i,n-i)));
        return arr;
    }
    vector<int> diffWaysToCompute(string exp) {
        int n=exp.size();
        return f(0,n,exp);
    }
};