class Solution(object):
    def longestCommonPrefix(self, strs):
        if not strs:
            return ""
        strs.sort()
        fst,lst=strs[0],strs[-1]
        i=0
        limit= min(len(fst),len(lst))
        
        while i<limit and fst[i]==lst[i]:
            i+=1
        
        return fst[:i]