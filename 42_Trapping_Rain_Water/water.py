DEBUG = False
class Solution:
    def countInBetweenZeros(height: list[int]) -> int:
        if len(height) < 3: return 0
        count, left = 0, -1
        for i, h in enumerate(height):
            if h != 0:
                if left != -1:
                    # Not first left
                    count += i - left - 1
                left = i
        return count

    def trap(self, height: list[int]) -> int:
        count = 0
        
        # Build a table by sorting "height" and removing all zeros
        offsets = [ i for i in sorted(set(height)) if i != 0 ]
        if DEBUG: print("offsets_before =", offsets)

        # Calculate offsets for each iteration (of moving x-axis)
        for i in range(len(offsets)-1, 0, -1):
            offsets[i] -= offsets[i-1]
        if DEBUG: print("offsets_after = ", offsets)

        # Move x-axis
        for offset in offsets:
            width = offset # width of the rectangle is equivalent to offset
            length = Solution.countInBetweenZeros(height)
            count += width * length
        if DEBUG: 
            print("---")
            print("width = ", offset)
            print("length = ", length)
            print("height = ", height)
        height = [ (h - offset) if h != 0 else 0 for h in height ]

        return count

# This solution works, but is Ω(n*log n) as it sorts the given height at first, we can do better

class DPSolution:
    def trap(self, height: list[int]) -> int:
        # Length of height
        n = len(height)
        if n == 0: return 0

        dp = [ [ -1, -1 ] for _ in height ]
        # dp[i][0] := maximum value to the left of i-th column (includng itself)
        # dp[i][1] := maximum value to the right of i-th column (including itself)

        # Initialize dp from left-most and right-most
        dp[0]  [0] = height[0]
        dp[n-1][1] = height[-1]

        # Left to right pass
        for i in range(1, n):
            # The LMV (Left Max Value) of i-th column is the larger value of the following two:
            #   1. LMV of (i-1)-th colunm
            #   2. height of i-th column
            dp[i][0] = max( dp[i-1][0], height[i] ) 
            
        # Right to left pass
        for i in range(n-2, -1, -1):
            # The RMV (Right Max Value) of i-th column is the larger value of the following two:
            #   1. RMV of (i+1)-th colunm
            #   2. height of i-th column
            dp[i][1] = max( dp[i+1][1], height[i] ) 

        if DEBUG: print(dp)

        result = 0
        for i,h in enumerate(height):
            if DEBUG: 
                print("---")
                print("i =", i)
                print("h =", h)
                print("dp[i][0] = ", dp[i][0])
                print("dp[i][1] = ", dp[i][1])
            result += min( dp[i][0], dp[i][1] ) - h
            if DEBUG: print("result =", result)

        return result

# This is O(N), but space wise it is O(N) as well. We can do better
# Notice that we don't actually need to store the whole dp table, we only need to keep two key variables along:
#   leftMax and rightMax

class ImprovedDPSolution:
    def trap(self, height: list[int]) -> int:
        # Length of height
        n = len(height)
        if n == 0: return 0

        result, leftMax, rightMax, l, r = 0, -1, -1, 0, n-1
        while l <= r:
            if leftMax <= rightMax:
                leftMax = max( leftMax, height[l] )
                result += leftMax - height[l]
                l += 1
            else:
                rightMax = max( rightMax, height[r] )
                result += rightMax - height[r]
                r -= 1

        return result



s = ImprovedDPSolution()
height = [4,2,0,3,2,5]
print(s.trap(height))
