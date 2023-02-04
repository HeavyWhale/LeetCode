from functools import total_ordering

@total_ordering
class Node:
    """Plain-old general node having its:
            - key for comparison (can be omitted if comparison is based on value)
            - value
            - left child (can be omitted if constucting a singly linked list)
            - right child
            - parent"""
    def __init__(self, key=None, value=None, left=None, right=None, parent=None) -> None:
        self.key = key
        self.value = value
        self.left = left
        self.right = right
        self.parent = parent
    
    def __eq__(self, __o: object) -> bool:
        return self.key == __o.key

    def __lt__(self, __o: object) -> bool:
        return self.key < __o.key

    def __str__(self) -> str:
        return f'{self.key=} {self.value=} {self.left=} {self.right=}'
    
    def __repr__(self) -> str:
        return f'<{self.key=}|{self.value=}>'

visited = set()

def getNeighbours(node: Node):
    pass

def dfs(root):
    for n in getNeighbours(root):
        if n not in visited:
            visited.add(n)
            dfs(n)

def bfs(root):
    pass
