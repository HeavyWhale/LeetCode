class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def isSymmetric_rec(l: Optional[TreeNode], r: Optional[TreeNode]) -> bool:
            if l == None and r == None:
                return True
            elif l == None or r == None:
                return False
            return (l.val == r.val) and \
                isSymmetric_rec(l.left, r.right) and isSymmetric_rec(l.right, r.left)
        return isSymmetric_rec(root.left, root.right)
