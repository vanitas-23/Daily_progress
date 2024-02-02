class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>res={12, 23, 34, 45, 56, 67, 78, 89, 123, 234, 345, 456, 567, 678, 789, 1234, 2345, 3456, 4567, 5678, 6789, 12345, 23456, 34567, 45678, 56789, 123456, 234567, 345678, 456789, 1234567, 2345678, 3456789, 12345678, 23456789, 123456789};
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
        
    }
};