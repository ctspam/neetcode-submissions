# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import sys
sys.setrecursionlimit(200000) 

class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        # recurring pattenr of the last node getting attached

        # so maybe like some recursive thing where Link(helper(head), head.first)
        # if not isinstance(s,Link):
        #     return ()
        # rest = removeNodes(s.rest)
        # if isinstance(rest, Link) and s.first < rest.first:
        #     rest
        # s.rest = rest
        # return s

        if head is None:
            return None
        rest = self.removeNodes(head.next)
        if rest is not None and head.val < rest.val:
            return rest
        head.next = rest
        return head