class Solution(object):
    def isMatch(self, s, p):
        n = len(s)
        m = len(p)
        
        # Initialize dp array with None values
        dp = [[None] * (m + 1) for _ in range(n + 1)]
        
        def solve(index1, index2):
            if index1 < 0 and index2 < 0:
                return True
            
            if index1 < 0:
                while index2 >= 0:
                    if p[index2] != '*':
                        return False
                    index2 -= 2
                return True
            
            if index1 >= 0 and index2 < 0:
                return False
            
            if dp[index1][index2] is not None:
                return dp[index1][index2]
            
            if s[index1] == p[index2] or p[index2] == '.':
                dp[index1][index2] = solve(index1 - 1, index2 - 1)
            elif p[index2] == '*':
                zero = solve(index1, index2 - 2)
                one = (index1 >= 0 and (s[index1] == p[index2 - 1] or p[index2 - 1] == '.')) and solve(index1 - 1, index2)
                dp[index1][index2] = zero or one
            else:
                dp[index1][index2] = False
            
            return dp[index1][index2]
        
        return solve(n - 1, m - 1)
