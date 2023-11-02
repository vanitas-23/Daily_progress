class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long>res;
        if(num%3!=0)
        return res;
        long long ele=num/3;
        res.push_back(ele-1);
        res.push_back(ele);
        res.push_back(ele+1);

        return res;
    }
};