class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        d = {}
        for i in s:
            d[i] = d.get(i, 0) + 1
        
        for i in t:
            if i not in d:
                return False
            d[i] = d[i] - 1
            if d[i] == 0:
                d.pop(i)
        
        return len(d) == 0