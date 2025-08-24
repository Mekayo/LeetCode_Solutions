class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left=0;
        int longest=0;
        for(int right=0; right<s.length();right++){
            
            // check is right is in the set 
            while(st.find(s[right])!=st.end()){
                st.erase(s[left]);
                left++;
            } 
            //check the size of substring 
            //right-left is alway be the length of the window 
            longest=max(longest,right-left+1);
            st.insert(s[right]);

        }

    return longest;
    }
};