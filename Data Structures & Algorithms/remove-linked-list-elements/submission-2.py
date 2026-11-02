# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        
        #lets first solve it by creating a new Linked list and recursion

        def helper(s):
            if s is None:
                return None
            if s.val == val:
                return helper(s.next)
            return ListNode(s.val, helper(s.next))
        return helper(head)