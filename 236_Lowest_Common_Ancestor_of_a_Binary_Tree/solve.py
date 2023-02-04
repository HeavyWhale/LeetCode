class mySolution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # path from root r to node p, from root r to node q
        r2p, r2q = [], []
        nodeQ, pathQ = [root], [[root]]
        while True:
            node, path = nodeQ.pop(0), pathQ.pop(0)
            if node.val == p.val:
                r2p = path
                if len(r2q) > 0: break
            elif node.val == q.val:
                r2q = path
                if len(r2p) > 0: break
            if node.left:
                nodeQ.append(node.left)
                pathQ.append(path + [node.left])
            if node.right:
                nodeQ.append(node.right)
                pathQ.append(path + [node.right])
        r2q_set = set(r2q)
        for node in reversed(r2p):
            if node in r2q_set: return node

class recSolution:
    def __init__(self):
        self.ans = None
    
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def traverseTree(node):
            if not node: return False
            left, right = traverseTree(node.left), traverseTree(node.right)
            mid = (node == p) or (node == q)
            if mid + left + right >= 2:
                self.ans = node
            return mid or left or right
        traverseTree(root)
        return self.ans


class ancestorDictSolution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        stack = [root]
        parent = {root: None}
        
        while p not in parent or q not in parent:
            node = stack.pop()
            if node.left:
                parent[node.left] = node
                stack.append(node.left)
            if node.right:
                parent[node.right] = node
                stack.append(node.right)
        
        ancestors = set()
        while p:
            ancestors.add(p)
            p = parent[p]
        while q not in ancestors:
            q = parent[q]
        return q

class optimalSolution():
    def lowestCommonAncestor(self, root, p, q):
        if root is None:
            return None
        
        left_res = self.lowestCommonAncestor(root.left, p, q)
        right_res = self.lowestCommonAncestor(root.right, p, q)
        
        if (left_res and right_res) or (root in [p, q]):
            return root
        else:
            return left_res or right_res
