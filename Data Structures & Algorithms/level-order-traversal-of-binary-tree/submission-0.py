# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    l = []
    def dfs(self,root, d):
        if not root:
            return
        if len(self.l) == d:
            self.l.append([])
        self.l[d].append(root.val)
        self.dfs(root.left,d+1)
        self.dfs(root.right, d+1)
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        self.dfs(root, 0)
        return self.l
        