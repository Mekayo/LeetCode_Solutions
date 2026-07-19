class Solution(object):
    def lengthOfLongestSubstring(self, s):
        st=set() 
        left=0
        longest=0

        for right in range(len(s)):

            while s[right] in st:
                st.remove(s[left])
                left+=1

            longest=max(right-left+1,longest)
            st.add(s[right])

        return longest