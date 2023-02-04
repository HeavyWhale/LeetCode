# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        fa = {}
        s, t = None, None
        
        def dfs(node: TreeNode) -> None:
            nonlocal s, t
            if node.val == startValue:
                s = node
            elif node.val == destValue:
                t = node
            if node.left != None:
                fa[node.left] = node
                dfs(node.left)
            if node.right != None:
                fa[node.right] = node
                dfs(node.right)
        dfs(root)
        
        def genPathStr(node: TreeNode) -> List[str]:
            res = []
            while node != root:
                parent = fa[node]
                res += 'L' if parent.left == node else 'R'
                node = parent
            return list(reversed(res))
        r2s, r2t = genPathStr(s), genPathStr(t)
        
        i = 0
        sl, tl = len(r2s), len(r2t)
        while i < min(sl, tl):
            if r2s[i] == r2t[i]:
                i += 1
            else:
                break
        
        return 'U' * (sl - i) + ''.join(r2t[i:])
        
        