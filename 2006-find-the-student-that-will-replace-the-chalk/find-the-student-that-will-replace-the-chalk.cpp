class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        long long sum = 0, i = 0;
        for (auto i : chalk) 
        sum += i;
        
        k %= sum;

        if (k == 0) 
        return 0;
        while (chalk[i] <= k)
        k = k - chalk[i++];
        return i;
    }
};