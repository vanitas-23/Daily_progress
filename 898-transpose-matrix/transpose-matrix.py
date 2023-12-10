class Solution:
    def transpose(self, A: 'List[List[int]]') -> 'List[List[int]]':
        
        l = [z for z in list(zip(*A))]
        return l