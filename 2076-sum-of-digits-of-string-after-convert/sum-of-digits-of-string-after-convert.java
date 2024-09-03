class Solution {
    public int getLucky(String s, int k) {
        StringBuilder str=new StringBuilder();
        for(int i=0;i<s.length();i++)
        str.append(s.charAt(i)-'a'+1);
        
        int a=0;
        for(char c : str.toString().toCharArray())
         a+=c-'0';
         if(a<10 || k==1)
        return a;
        for(int i=1;i<k;i++){
            str=new StringBuilder();
            str.append(a);
         a=0;
        for(char c : str.toString().toCharArray())
         a+=c-'0';
        }
return a;
    }
}