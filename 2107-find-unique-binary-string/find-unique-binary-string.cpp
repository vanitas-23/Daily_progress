class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        unordered_set<unsigned long>st;

        for(auto i:nums)
        {
           st.insert(stoi(i,0,2));
        }
        
        for(int i=1;i<(2<<n);i++)
        if(st.find(i)==st.end())
        {
            string binary  ("");
    int mask = 1;
    for(int j = 0; j < n; j++)
    {
    if((mask&i) >= 1)
        binary = "1"+binary;
    else
        binary = "0"+binary;
     mask<<=1;
 }
 return binary;
        }


        for(auto i:st)
        cout<<i<<" ";
        return "j";
    }
};