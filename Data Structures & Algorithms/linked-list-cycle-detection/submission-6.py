# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        

        # seen = set()
        # current = head
        
        # while current:
        #     if current in seen:
        #         return True

        #     seen.add(current)
        #     current = current.next

        # return False

    # this approach is O(n) imes since each node gets visited at most once.and the space is o(n) because of the set, int the worst case every node gets added before you hit None or find the repeat so with 10k nodes the set holds 10k entries

    # now lets find a better approach to this which is the tortoise and hare
    # this allows u to test with onlytwo pointers called fast and slow so fast moves double slow but if slow is fast or fast is slow meaning that fast caught up with slow then that means that a cycle list is found 

        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if fast is slow:
                return True

        return False