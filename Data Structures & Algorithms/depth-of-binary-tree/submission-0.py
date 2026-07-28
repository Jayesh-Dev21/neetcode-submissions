# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, r: Optional[TreeNode]) -> int:
        if(r==None):
            return 0
        return max(1 + self.maxDepth(r.left), 1 + self.maxDepth(r.right));