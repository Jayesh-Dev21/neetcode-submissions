# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    T = 0
    def dfs(root) -> int:
        if not root:
            return 0
        l = self.dfs(root.left)
        r = self.dfs(root.right)
        T = max(T,r+l)
        return 1+max(r,l)
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.dfs(root)
        return T
        