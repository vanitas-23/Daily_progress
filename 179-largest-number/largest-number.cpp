class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans="";
        vector<string>arr;
        auto cmp=[](string a,string b)
        {return a+b>b+a;};
        
        for(auto i:nums)
        arr.push_back(to_string(i));
        sort(arr.begin(),arr.end(),cmp);
        if(arr[0]=="0")
        return "0";
        for(auto i:arr)
        ans+=i;
        return ans;
    }
};