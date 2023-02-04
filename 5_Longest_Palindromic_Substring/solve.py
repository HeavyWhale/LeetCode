class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expandFrom(left, right) -> tuple[int, int]:
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return (right - left - 1, left + 1)
        
        if not s:
            return ""
    
        n = len(s)
        longest, start = 1, 0
        for middle in range(n):
            longest, start = max(
                (longest, start), 
                expandFrom(middle, middle),     # middle is at a single char
                expandFrom(middle, middle+1)    # middle is in between two chars
            )
        return s[start: start + longest]
    
    
    def longestPalindrome_DP(self, s: str) -> str:
        if not s:
            return ""
        
        n = len(s)
        
        start, longest = 0, 1
        # isPalindromeMem is a 2D-matrix of boolean serves as a memorization repo for dp where:
        #   isPalindromeMem[i][j] == True if and only if s[i:j+1] is a palindrom
        # For dp, we have 
        #   isPalindromeMem[i][j] == True if and only if isPalindromeMem[i+1][j-1] and s[i] == s[j]
        isPalindromeMem = [ [False] * len(s) for _ in range(n) ]
        
        # Initialization
        for i in range(n):
            isPalindromeMem[i][i] = True    # one letter is a palindrom
        for i in range(1, n):
            isPalindromeMem[i][i-1] = True  # empty string is a palindrom
        
        # Iterate through s
        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                isPalindromeMem[i][j] = isPalindromeMem[i+1][j-1] and s[i] == s[j]
                if isPalindromeMem[i][j] and length > longest:
                    start, longest = i, length
        
        return s[start: start + longest]
