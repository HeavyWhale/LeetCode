# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight

def show(node: Node, padding=''):
    if node == None: return
    if node.isLeaf:
        print("{}[Leaf: val={}]".format(padding, node.val))
    else:
        print("{}[Internal Node]".format(padding))
        if node.topLeft: show(node.topLeft, padding+"  └")
        if node.topRight: show(node.topRight, padding+"  └")
        if node.bottomLeft: show(node.bottomLeft, padding+"  └")
        if node.bottomRight: show(node.bottomRight, padding+"  └")


class Solution:
    def construct(self, grid: list[list[int]]) -> 'Node':
        def isLeaf(x1: int, y1: int, x2: int, y2: int) -> bool:
            ref = grid[x1][y1]
            for i in range(x1, x2):
                for j in range(y1, y2):
                    if grid[i][j] != ref: return False
            return True
        def construct_rec(x1: int, y1: int, x2: int, y2: int) -> 'Node':
            if isLeaf(x1, y1, x2, y2):
                return Node(grid[x1][y1], True, None, None, None, None)
            else:
                rMid, cMid = (x1 + x2) // 2, (y1 + y2) // 2
                return Node(True, False,\
                    topLeft=construct_rec(x1, y1, rMid, cMid),\
                    topRight=construct_rec(x1, cMid, rMid, y2),\
                    bottomLeft=construct_rec(rMid, y1, x2, cMid),\
                    bottomRight=construct_rec(rMid, cMid, x2, y2))
        return construct_rec(0, 0, len(grid), len(grid))
        
grid = [
    [1,1,1,1,0,0,0,0],
    [1,1,1,1,0,0,0,0],
    [1,1,1,1,1,1,1,1],
    [1,1,1,1,1,1,1,1],
    [1,1,1,1,0,0,0,0],
    [1,1,1,1,0,0,0,0],
    [1,1,1,1,0,0,0,0],
    [1,1,1,1,0,0,0,0]
]
# print(grid[4][0])
# grid = [
#     [1,1,1,1,1,1,1,1],
#     [1,1,1,1,1,1,1,1],
#     [1,1,1,1,1,1,1,1],
#     [1,1,1,1,1,1,1,1],
#     [1,1,1,1,1,1,1,1],
#     [1,1,1,1,1,1,1,1],
#     [1,1,1,1,1,1,1,1],
#     [1,1,1,1,1,1,1,1]
# ]
s = Solution()
show(s.construct(grid))
