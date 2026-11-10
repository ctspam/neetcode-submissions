# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        
        # we ncan run recursion on these tree nodesso like dfs to compare each value and there are certain cases that need otbe figured out

        # case 1:
        # where both p and q are none
        if p is None and q is None:
            return True

        # this is the second case where only on of them is none then u return False, these are like our base cases btw
        if p is None or q is None:
            return False

        # case 3 where both nodes exist but the values are different
        if p.val != q.val:
            return False

        # and then last case where the values match meaning that keep moving on 

        left_check = self.isSameTree(p.left, q.left)
        right_check = self.isSameTree(p.right, q.right)
        # need to check if True and False which is False because only gives True when boths side are True
        return left_check and right_check