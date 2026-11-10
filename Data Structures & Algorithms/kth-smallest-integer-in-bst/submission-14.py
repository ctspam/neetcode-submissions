# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        # ifeel like the brute force solution to this is adding this to a list each value and then sorting the list and then do O(1) lookup but space complexity will be O(n) and time complexity will be O(nlogn) neause of the sort

        #oh okay wait this isa BST so like i feel like u can reduce the amoutns by going either left or right or 

        # we can create a list to hodl the values and then go left and rhen right inorder for bst

        res = []

        # we can also use hleper func bc without it then every call would run the res again n start a new empty list
        def inorder(node):

            # since we're using recursiong we want to stop when theres no node here and then return 
            if node is None:
                return
            inorder(node.left)
            res.append(node.val)
            inorder(node.right)

        inorder(root)
        return res[k-1]