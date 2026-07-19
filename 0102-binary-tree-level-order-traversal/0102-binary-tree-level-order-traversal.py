# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[List[int]]
        """
        if not root: return []

        q =deque()
        q.append(root)
        res = list()
        while q:
            siz=len(q)
            cur=list()
            for _ in range(siz):
                temp =q.popleft()
                # q.popleft()
                cur.append(temp.val)

                if temp.left: q.append(temp.left)

                if temp.right : q.append(temp.right)
            
            res.append(cur)

        return res

                
            




        