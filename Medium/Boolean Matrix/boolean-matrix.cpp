//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &mat)
    {
        // code here 
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(mat[i][j]==1){
                for(int k=j+1;k<m && mat[i][k]!=1;k++)
                mat[i][k]=2;
                for(int k=j-1;k>=0 && mat[i][k]!=1;k--)
                mat[i][k]=2;
                for(int k=i+1;k<n && mat[k][j]!=1;k++)
                mat[k][j]=2;
                for(int k=i-1;k>=0 && mat[k][j]!=1;k--)
                mat[k][j]=2;
            }
        }
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(mat[i][j]==2)
        mat[i][j]=1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends