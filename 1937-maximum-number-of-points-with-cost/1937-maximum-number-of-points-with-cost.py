class Solution(object):
    def bruteForce(self, points, rows, cols):
        prev = points[0]
        
        for row in range(1, rows):
            curr = [0]*cols
            for col in range(cols):
                for k in range(cols):
                    curr[col] = max(curr[col], prev[k]+points[row][col]-abs(k-col))
            prev = curr
        
        return max(prev)
    
    def optimized(self, points, rows, cols):
        prev = points[0]
        
        for row in range(1, rows):
            left = [0]*cols
            left[0] = prev[0]
            for col in range(1, cols):
                left[col] = max(prev[col], left[col-1]-1)
            
            right = [0]*cols
            right[-1] = prev[-1]
            for col in range(cols-2, -1, -1):
                right[col] = max(prev[col], right[col+1]-1)
                
            curr = [0]*cols
            for col in range(cols):
                curr[col] = points[row][col] + max(left[col], right[col])
                
            prev = curr
        
        return max(prev)
        
    def maxPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        rows = len(points)
        cols = len(points[0])
        
        # return self.bruteForce(points, rows, cols)
        
        return self.optimized(points, rows, cols)

        
        