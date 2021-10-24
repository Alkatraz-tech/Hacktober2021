# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def solve(self,root,min_val,max_val):
      if root == None:
         return True
      if (root.val <= min_val or root.val >=max_val):
         return False
      return self.solve(root.left,min_val,root.val) and self.solve(root.right,root.val,max_val)
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """

        return self.solve(root, float('-inf'),float('inf'))
        
        
            