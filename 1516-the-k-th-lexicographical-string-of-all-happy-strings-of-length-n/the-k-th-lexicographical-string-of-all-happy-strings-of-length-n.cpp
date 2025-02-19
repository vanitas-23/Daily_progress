class Solution {
public:
    void f(int i,int n,int last,vector<string>& arr,string& temp)
    {
        
        if(i==n)
        {
        //cout<<temp<<" ";
        arr.push_back(temp);
        return ;
        }
        for(char c='a';c<='c';c++)
        if(c-'a'!=last)
        {
            temp.push_back(c);
            f(i+1,n,c-'a',arr,temp);
            temp.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<string>arr;
        string temp="";
        f(0,n,-1,arr,temp);
        //cout<<arr.size()<<" ";
        if(arr.size()<k)
        return "";
        return arr[k-1];
    }
};