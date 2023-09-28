//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:

    long long toh(int n, int from, int to, int aux) {
        // Your code here
    
            if(n==1){
                cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
                return 1;
            }
            
            
            long long steps=0;
            steps=1+toh(n-1,from,aux,to);
            cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
            steps+=toh(n-1,aux,to,from);
            //cout<<"move disk "<<n<<" from rod "<<aux<<" to rod "<<to<<endl;
            return steps;
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}



// } Driver Code Ends