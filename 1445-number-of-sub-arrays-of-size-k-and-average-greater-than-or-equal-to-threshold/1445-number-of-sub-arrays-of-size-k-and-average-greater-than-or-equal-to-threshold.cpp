class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i=0;
        int j =0;
        int sum =0;
        int count=0;
        while(j<arr.size())
        {
            sum = sum + arr[j];
            if(j-i+1 == k)
            {
                int val = sum/k;
                if(val >=threshold)
                {
                    count++;
                }
                sum = sum - arr[i];
                i++;
            }
            j++;
        }
        return count;
    }
};