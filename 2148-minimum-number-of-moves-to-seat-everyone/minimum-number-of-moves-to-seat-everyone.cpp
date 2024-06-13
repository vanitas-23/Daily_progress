class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& stu) {
        sort(seats.begin(),seats.end());
        sort(stu.begin(),stu.end());
        int ans=0;
        int n=stu.size();
        for(int i=0;i<n;i++)
        ans+=abs(seats[i]-stu[i]);

        return ans;
    }
};