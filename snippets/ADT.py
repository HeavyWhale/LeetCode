import logging
from functools import total_ordering

DEBUG = True

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
    
class BinaryTree_Arr:
    """Binary tree implemented using an array"""

    # Class (static) variable indicating left or right child.
    _LEFT, _RIGHT = 1, 2  
    ROOT = 0

    def __init__(self) -> None:
        self.__A = []
        self.__size = 0

    def increase_size(self) -> None:
        self.__size += 1

    def decrease_size(self) -> None:
        self.__size -= 1

    def is_valid_index(self, index: int) -> bool:
        return 0 <= index < self.__size

    def is_leaf(self, index: int) -> bool:
        return (self.__A[BinaryTree_Arr.left(index)] is None and 
                self.__A[BinaryTree_Arr.right(index)] is None)

    def last(n: int) -> int:
        return n - 1

    def left(index: int) -> int:
        """Get the left index of [index]"""
        return 2*index + BinaryTree_Arr._LEFT
    
    def right(index: int) -> int:
        """Get the right index of [right]"""
        return 2*index + BinaryTree_Arr._RIGHT

    def parent(index: int) -> int:
        """Get the parent index of [right]"""
        return (index-1) // 2

    def __len__(self) -> int:
        return self.__size

    def __getitem__(self, index: int) -> any:
        """Get node at index"""
        if not isinstance(index, int):
            raise TypeError(f'Illegal index: Indices must be integers')
        return self.__A[index]

    def __setitem__(self, index: int, item: any) -> None:
        """Set item at index"""
        logging.info(f'''ENTRY: {index=}, {item=}
            {self.__A=}
            {self.__size=}
        ''')

        if not 0 <= index:
            raise IndexError(f'Illegal index: Given node at index {index} cannot be set')
        
        rindex = BinaryTree_Arr.right(index)
        if not rindex < len(self.__A):
            # We must extend the list to at least rindexof(index) 
            # and fill the gap by None so that its l, rchild are 
            # None
            self.__A.extend((None,) * (rindex - len(self.__A) + 1))
            logging.info('self.__arr extended')

        """
        item    self.__arr[index]   Result
        0       0                   pass
        0       1                   self.__size -= 1
        1       0                   self.__size += 1
        1       1                   pass
        """
        self.__A[index] = item

        logging.info(f'''EXIT: {index=}, {item=}
            {self.__A=}
            {self.__size=}
        ''')

    def __delitem__(self, index: int) -> None:
        """Delete item at index"""
        logging.info(f'''ENTRY: {index=}
            {self.__A=}
            {self.__size=}
        ''')

        if not isinstance(index, int):
            raise TypeError(f'Illegal index: Indices must be integers')
        if not 0 <= index < len(self.__A):
            raise IndexError(f'Illegal index: Given node at index {index} does not exist')
        del self.__A[index]

        logging.info(f'''EXIT: {index=}
            {self.__A=}
            {self.__size=}
        ''')

    def __repr__(self) -> str:
        return self.__A.__repr__()
    

"""
    All following data structures can be seen as different forms of 
    Priority Queue:
        An ADT (Abstract Data Type) consisting of a collection of
        items (each having a priority) with operations:
            - insert: inserting an item tagged with a priority;
            - deleteMax: removing the item of highest priority.
    For example:
     1. Queue is a PQ with its item insertion time as priority key: the
        earlier, the higher its priority;
     2. Stack is the same with queue in which it uses its item insertion 
        time as priority key, but the earlier, the lower its priority;
     3. (Max) Heap is a PQ with its item value as priority key: the larger
        its value, the higher its priority.
"""


class Queue_Arr:
    def __init__(self) -> None:
        self.q = list()
        
    def enqueue(self, item) -> None:
        self.q.append(item)
        
    def dequeue(self) -> any:
        return self.q.pop(0)
    
    def front(self) -> any:
        return self.q[0]
    
    def rear(self) -> any:
        return self.q[-1]
    
    def isEmpty(self) -> bool:
        return len(self.q) == 0


class Queue_LinkedList:
    def __init__(self) -> None:
        self.head = self.tail = None
    
    def enqueue(self, item) -> None:
        if self.head is None:
            self.head = self.tail = Node(value=item)
        else:
            self.tail.right = Node(value=item)
            self.tail = self.tail.right

    def dequeue(self) -> any:
        temp = self.head.value
        if self.head is self.tail:
            self.head = self.tail = None
        else:
            self.head = self.head.right
        return temp
    
    def front(self) -> any:
        return self.head.value

    def rear(self) -> any:
        return self.tail.value
    
    def isEmpty(self) -> bool:
        return self.head == None

class Stack_Arr:
    def __init__(self) -> None:
        self.s = list()
        
    def push(self, item) -> None:
        self.s.append(item)
        
    def pop(self) -> any:
        return self.s.pop(-1)
    
    def top(self) -> any:
        return self.s[-1]
    
    def bottom(self) -> any:
        return self.s[0]
    
    def isEmpty(self) -> bool:
        return len(self.s) == 0


class Stack_LinkedList:
    def __init__(self) -> None:
        self.head = self.tail = None
    
    def push(self, item) -> None:
        if self.head is None:
            self.head = self.tail = Node(value=item)
        else:
            self.head = Node(value=item, right=self.head)

    def pop(self) -> any:
        temp = self.head.value
        if self.head is self.tail:
            self.head = self.tail = None
        else:
            self.head = self.head.right
        return temp
    
    def top(self) -> any:
        return self.head.value

    def bottom(self) -> any:
        return self.tail.value
    
    def isEmpty(self) -> bool:
        return self.head is None

class MaxHeap_LinkedList:
    def __init__(self) -> None:
        self.__A = BinaryTree_Arr()

    def top(self) -> int:
        return self.__A[BinaryTree_Arr.ROOT]

    def last(n: int) -> int:
        return n - 1
    
    def fix_up(self, index: int) -> None:
        if not 0 <= index < len(self.__A):
            raise IndexError(f'Illegal index: Given node at index {index} does not exist')
        while (self.__A.is_valid_index(pindex := BinaryTree_Arr.parent(index)) and 
               self.__A[pindex] < self.__A[index]):
            self.__A[index], self.__A[pindex] = self.__A[pindex], self.__A[index]
            index = pindex

    def fix_down(self, size: int, index: int) -> None:
        while not self.__A.is_leaf(index):
            logging.info(f'''<<< WHILE ENTRY: {index=}, {size=}
                {self.__A=}
            ''')
            cmp_i = BinaryTree_Arr.left(index)
            if cmp_i < MaxHeap_LinkedList.last(size) and self.__A[cmp_i + 1] > self.__A[cmp_i]:
                cmp_i += 1
            if self.__A[index] >= self.__A[cmp_i]: break
            self.__A[index], self.__A[cmp_i] = self.__A[cmp_i], self.__A[index]
            index = cmp_i
            logging.info(f'''>>> WHILE CONTINUE: {index=}, {size=}
                {self.__A=}
            ''')

    def insert(self, item: Node) -> None:
        self.__A.increase_size()
        l = MaxHeap_LinkedList.last(len(self.__A))
        self.__A[l] = item
        self.fix_up(l)

    def deleteMax(self) -> Node:
        l = MaxHeap_LinkedList.last(len(self.__A))
        self.__A[BinaryTree_Arr.ROOT], self.__A[l] = self.__A[l], self.__A[BinaryTree_Arr.ROOT]
        self.__A.decrease_size()
        temp = self.__A[l]
        self.__A[l] = None
        self.fix_down(len(self.__A), BinaryTree_Arr.ROOT)
        return temp

    def __repr__(self) -> str:
        return self.__A.__repr__()

def main():
    level = logging.DEBUG
    fmt = '[%(levelname)s] %(asctime)s %(funcName)s - %(message)s @ line %(lineno)d'
    if DEBUG: logging.basicConfig(level=level, format=fmt)

if __name__ == '__main__':
    main()

main()
N = [ Node(key=i, value=f'Node {i}') for i in range(10) ]
h = MaxHeap_LinkedList()
for i in range(10):
    h.insert(N[i])
