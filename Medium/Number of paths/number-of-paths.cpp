//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    public:
    int MOD = 1000000007;
    long long  numberOfPaths(int M, int N)
    {
        
       int t = M + N - 2;
        int r = M - 1;
        long res = 1;
         
    
        for (int i = 1; i <= r; i++) {
            res = (res * (t - r + i) % MOD) * modInverse(i, MOD) % MOD;
        }
    
        return res;
    }
    
    long modInverse(int a, int m) {
    long m0 = m;
    long x0 = 0;
    long x1 = 1;

    while (a > 1) {
            long q = a / m;
            long t = m;
    
            m = a % m;
            a = (int)t;
    
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }

        if (x1 < 0) {
            x1 += m0;
        }

        return x1;
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends