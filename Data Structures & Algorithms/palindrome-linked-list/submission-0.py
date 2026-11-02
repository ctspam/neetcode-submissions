# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        self.cur = head

        def helper(rec):
            if rec is not None:
                if not helper(rec.next):
                    return False
                if rec.val != self.cur.val:
                    return False

                self.cur = self.cur.next
            return True
        return helper(head)
