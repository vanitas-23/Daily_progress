class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        string str="";
        for(int i=0;i<n;i++)
        {
          nums[i][i]=='0'?str+='1':str+='0';
        }
        return str;
    }
};