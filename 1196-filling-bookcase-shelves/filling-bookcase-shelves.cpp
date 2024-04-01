class Solution {
public:
    int f(int i,int n,vector<vector<int>>& books, int shelfWidth,int avail,int curr,vector<vector<int>>& dp)
    {
        if(i==n)
        return curr;
        if(dp[i][avail]!=-1)
        return dp[i][avail];
        int useCurr=1e9;
        if(books[i][0]<=avail)
        useCurr = f(i+1,n,books,shelfWidth,avail-books[i][0],max(curr,books[i][1]),dp);
        int useNew = curr + f(i+1,n,books,shelfWidth,shelfWidth-books[i][0],books[i][1],dp);

        return dp[i][avail]=min(useCurr,useNew);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<vector<int>>dp(n,vector<int>(shelfWidth+1,-1));
        return f(0,n,books,shelfWidth,shelfWidth,0,dp);
    }
};