# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
    


        # measure if empty tree or not so no levels
        if not root: 
            return []

        # will hold one list per level
        result = []
        # level 1 is just the root
        queue = deque([root])

        # each round of this loop handles one level
        while queue:
            # levels for this level
            level = []
            # how many nodes are on this level because then we can remove exactly those nodes and append to our results list
            size = len(queue)

            for _ in range(size):
                #taking from the front
                node = queue.popleft()
                # record its value
                level.append(node.val)

                if node.left:
                    # child waits for the next round
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            # this level is done so save it 
            result.append(level)

        return result


