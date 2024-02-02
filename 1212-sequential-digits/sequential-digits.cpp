class Solution {
public:
    string digits="123456789";
    void f(vector<int>& res,int sz)
    {
       for(int i=0;i<=9-sz;i++)
       {
           string temp=digits.substr(i,sz);
           res.push_back(stoi(temp));
       }
    }
    vector<int> sequentialDigits(int low, int high) {
        string l=to_string(low);
        string h=to_string(high);
        vector<int>res;
        for(int i=l.size();i<=h.size();i++)
        f(res,i);
        auto it1=lower_bound(res.begin(),res.end(),low);
        auto it2=lower_bound(res.begin(),res.end(),high);
        vector<int>ans;
        while(it1!=it2)
        {
            ans.push_back(*it1);
            it1++;
        }
        if(it2!=res.end())
        if(*it2==high)
        ans.push_back(high);
        return ans;
        //return res;
    }
};