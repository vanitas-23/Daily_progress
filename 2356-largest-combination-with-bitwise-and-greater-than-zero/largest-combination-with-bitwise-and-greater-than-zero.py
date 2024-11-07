class Solution:
    def largestCombination(self, can: List[int]) -> int:
        l=[0]*31
        for i in can:
            for j in range(0,32):
                if i&(1<<j):
                    l[j]+=1
        return max(l)
        