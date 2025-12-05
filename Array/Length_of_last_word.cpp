// LeetCode #58: length of last word
// https://leetcode.com/problems/length-of-last-word

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        bool counting=false;
        for(int j=s.length()-1;j>=0;--j){
        
            if(s[j]!=' '){
                counting=true;
               len++;
            }
            else if(counting) break;
        }
        
    return len;
    }
};