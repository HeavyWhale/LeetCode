# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def sortedListToBST(self, head):
        if head == None: return None
        
        # convert the single linked list into an array
        l = []
        while head != None:
            l.append(head.val)
            head = head.next
        
        def sortedArrayToBST(left: int, right: int) -> TreeNode:
            # l is exposed to this inner function
            if left > right: return None
            mid = (left + right) // 2
            return TreeNode(l[mid], sortedArrayToBST(left, mid-1), sortedArrayToBST(mid+1, right))
        
        return sortedArrayToBST(0, len(l)-1)

def printBST(root, padding=''):
    if root == None: 
        print(padding+"None")
        return
    print(padding+str(root.val))
    printBST(root.left, padding+'  ')
    printBST(root.right, padding+'  ')
root = \
    TreeNode(1, \
        TreeNode(-2, \
            TreeNode(-7, None, None), \
            TreeNode(0, None, None)), \
        TreeNode(9, \
            TreeNode(3, None, None), \
            None))
# printBST(root)
head = ListNode(-10, ListNode(-3, ListNode(0, ListNode(5, ListNode(9, None)))))
s = Solution()
printBST(s.sortedListToBST(head))
