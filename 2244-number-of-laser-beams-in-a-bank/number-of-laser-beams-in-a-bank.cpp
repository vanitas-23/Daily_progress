class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>arr;
        for(auto i:bank){
            int cnt=0;
            for(char c:i)
            if(c=='1')
            cnt++;
            if(cnt>0)
            arr.push_back(cnt);
        }
        if(arr.size()<2)
        return 0;
        int res=0;
        for(int i=1;i<arr.size();i++)
        res+=arr[i]*arr[i-1];

        return res;

    }
};