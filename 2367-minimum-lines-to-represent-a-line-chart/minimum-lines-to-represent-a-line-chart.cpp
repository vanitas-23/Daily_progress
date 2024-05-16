class Solution {
public:
    int minimumLines(vector<vector<int>> &stockPrices)
{
    int n = stockPrices.size();
    if(n == 1) {
        return 0;
    }
    sort(stockPrices.begin(), stockPrices.end());

    long double x1 = 1.0 * stockPrices[0][0];
    long double y1 = 1.0 * stockPrices[0][1];
    long double x2 = 1.0 * stockPrices[1][0];
    long double y2 = 1.0 * stockPrices[1][1];
    int count = 1;
    long double slope;

    if (y2 - y1 == 0.0)
    {
        slope = 1e9;
    }
    else
    {
        slope = (y2 - y1) / (x2 - x1);
    }

    for (int i = 2; i < n; i++)
    {
        long double x1 = 1.0 * stockPrices[i][0];
        long double y1 = 1.0 * stockPrices[i][1];
        long double x2 = 1.0 * stockPrices[i - 1][0];
        long double y2 = 1.0 * stockPrices[i - 1][1];
        long double currslope;

        if (y2 - y1 == 0.0)
        {
            currslope = 1e9;
        }
        else
        {
            currslope = (y2 - y1) / (x2 - x1);
        }

        if (currslope != slope)
        {
            count++;
            slope = currslope;
        }
    }
    return count;
}
};