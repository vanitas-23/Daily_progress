class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>res(n);
        if(k==0)
        {
            for(int i=0;i<n;i++)
            res[i]=0;
            return res;
        }
        for(int i=0;i<n;i++)
        {
            int j;
            if(k>0)
            j=(i+1)%n;
            else
            j=(i-1+n)%n;
            int sum=0;
            int re=abs(k);
            while(re>0)
            {
                sum+=code[j];
                if(k>0)
                j++;
                else
                j--;
                j=(j+n)%n;
                re--;
            }
            res[i]=sum;
        }
        return res;
    }
};