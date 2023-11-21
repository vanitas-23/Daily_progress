class Solution {
public:
int rev(int num) {
        int result = 0;
        while (num > 0) {
            result = result * 10 + num % 10;
            num /= 10;
        }
        
        return result;
    }
    int mod=1e9+7;
    int countNicePairs(vector<int>& nums) {
        vector<int>arr=nums;
        int n=nums.size();
        for(int i=0;i<n;i++)
            arr[i]=rev(nums[i]);
        
        for(int i=0;i<n;i++)
        arr[i]-=nums[i];
      //  cout<<n<<" ";
        sort(arr.begin(),arr.end());
        int ans=0;
        int curr=arr[0];
        int temp=1;
        for(int i=1;i<n;i++){
            if(arr[i]==curr)
            temp++;
            else{
                curr=arr[i];
                ans = (ans%mod + (temp*(temp-1))/2)%mod;
                temp=1;
            }
        }
     //   cout<<temp;
        ans = (ans%mod + (temp*1LL*(temp-1))/2)%mod;
        return ans;
    }
};