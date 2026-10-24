# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def isPalindrome(self, head):
        if head is None or head.next is None:
            return True

        slow,fast=head,head

        while fast and fast.next :
            slow=slow.next
            fast=fast.next.next
        
        prev=None
        cur=slow
        # reverse the right half
        while cur:
            temp=cur.next
            cur.next=prev
            prev=cur
            cur=temp
        
        left,right=head,prev

        while right:
            if left.val != right.val :
                return False
            left,right=left.next,right.next
        
        return True