class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        tlen=len(t)
        slen=len(s)
        if tlen<slen:
            return False
        S_at,T_at=0,0

        while S_at<slen and T_at<tlen :
            if(s[S_at]==t[T_at]):
                S_at+=1
            
            T_at+=1

        return S_at==slen