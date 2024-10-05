class Solution:
    def usingCounter(self, s1, s2, n1, n2):
        c1 = Counter(s1)
        
        for i in range(n2-n1+1):
            c2 = Counter(s2[i:n1+i])
            if c1 == c2:
                return True

        return False
        
        
    def usingCustomMap(self, s1, s2, n1, n2):
        def create_map(s):
            freq_map = {}
            for c in s:
                freq_map[c] = freq_map.get(c, 0) + 1
            return freq_map
        
        mp1 = create_map(s1)
        
        for i in range(n2-n1+1):
            mp2 = create_map(s2[i:n1+i])
            if mp1 == mp2:
                return True
        return False
                
            
            
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n1, n2 = len(s1), len(s2)
        
        # return self.usingCounter(s1, s2, n1, n2)
        
        return self.usingCustomMap(s1, s2, n1, n2)