class Solution:
    def minEnd(self, n: int, x: int) -> int:
        arr=[]
        for i in range(64):
            if(x&(1<<i)):
                continue
            arr.append(i)
        n-=1
        j=0
        ans=x
        for i in range(64):
            if(n&(1<<i)):
                ans|=(1<<arr[j])
            j+=1
        return ans
        