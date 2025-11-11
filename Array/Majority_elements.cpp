// LeetCode #169: marjorit elements
// https://leetcode.com/problems/marjorit-elements

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int i:nums){
            mp[i]++;
        }
        for(auto n:mp){
            if(n.second>(nums.size()/2)){
                return n.first;
            }
        }
     return -1;
     }
};

