# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        # this just means that the node to the left always has to be smaller than the root and the node.right always have to be bigger than the root so u can start with the root maybe u use some recursive function

        def helper(node, low, high):
            # this means an empty subtree is valid 
            if not node:
                return True 
            # node must be strictly between low and high
            if not (low < node.val < high):
                return False

            return (helper(node.left, low, node.val) and helper(node.right, node.val, high))
        # root has no limits
        return helper(root, float('-inf'), float('inf'))