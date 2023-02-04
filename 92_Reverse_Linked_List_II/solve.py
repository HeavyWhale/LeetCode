# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        def reverse(head: Optional[ListNode], length: int) -> Optional[ListNode]:
            """Return new head of a linked list by reversing [length] nodes at front"""
            cur, prev = head, None
            for _ in range(length):
                temp = cur.next
                cur.next = prev
                prev = cur
                cur = temp
            # [head] is now the new tail, hook up (possible) remaining nodes.
            head.next = cur     
            return prev
        
        cur = dummy = ListNode(next=head)
        for _ in range(left - 1):
            cur = cur.next
        cur.next = reverse(cur.next, right - left + 1)
        
        return dummy.next
