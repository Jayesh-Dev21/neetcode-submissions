# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self, node, Max):
        if not node:
            return 0
        good = 0
        if(node.val >= Max):
            Max = max(node.val, Max)
            good = 1
        good += self.dfs(node.right, Max) + self.dfs(node.left, Max)
        return good 

    def goodNodes(self, root: TreeNode) -> int:
        return self.dfs(root, root.val)