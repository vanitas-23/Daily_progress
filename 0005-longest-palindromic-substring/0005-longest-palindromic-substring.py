class Node:
    def __init__(self, len, sfx = None):
        self.len = len
        self.sfx = sfx
        self.next = {}
        
class Solution:
    def longestPalindrome(self, s: str) -> str:
        curr = empty = Node(0, Node(-1))
        ans_len = ans_idx = 0
        for i, c in enumerate(s):
            while i <= curr.len or s[i-1-curr.len] != c:
                curr = curr.sfx
            if c in curr.next:
                curr = curr.next[c]
                continue
            node = curr.next[c] = Node(curr.len+2, empty)
            if node.len > ans_len:
                ans_len, ans_idx = node.len, i-node.len+1
            if node.len > 1:
                curr = curr.sfx
                while i <= curr.len or s[i-1-curr.len] != c:
                    curr = curr.sfx
                node.sfx = curr.next[c]
            curr = node
        return s[ans_idx:ans_idx+ans_len]