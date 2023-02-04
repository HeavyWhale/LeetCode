class Solution:
    def reverseWords(self, s: str) -> str:
        s = ' ' + s + ' '
        res = ""
        j = 0
        for i, ch in enumerate(reversed(s)):
            i = ~i
            print("--- i = {}, ch = {}".format(i, ch if ch != ' ' else '\' \''))
            if ch == ' ':
                if j == 0: continue
                res += s[i+1:j+1] + ' '
                j = 0
            else:
                if j == 0: j = i
        return res[:-1]

s = "the sky is blue"
so = Solution()
print(so.reverseWords(s))
