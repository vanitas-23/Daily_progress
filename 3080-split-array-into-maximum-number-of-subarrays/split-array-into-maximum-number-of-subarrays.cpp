class Solution {
public:

 int maxSubarrays(vector<int>& nums) {
    int n=nums.size();
    int cnt=0, andd=nums[0];  
	
    for(int i=0; i<n; i++){ 
        andd&=nums[i];
        if(i==n-1){
            andd&=nums[i];
            break;
        }
        
        if(andd==0){ 
            cnt++;
            andd=nums[i+1];
        }
    }
   
    if(andd==0 || cnt==0) cnt++;
    return cnt;  
  }
};