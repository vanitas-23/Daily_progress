class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        if n==1:
            return '0'
        len=(1<<n)
        if(k==len//2):
            return '1'
        if(k<len//2):
            return self.findKthBit(n-1,k)
        return '1' if self.findKthBit(n-1,len-k)=='0' else '0'
        