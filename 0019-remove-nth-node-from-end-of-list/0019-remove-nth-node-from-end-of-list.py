# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        slow=head
        fast=head

        for _ in range(n):
            fast=fast.next
        
        if fast is None:
            return head.next
        
        while not fast is None and not fast.next is None:
            slow=slow.next
            fast=fast.next
        
        slow.next=slow.next.next
        return head