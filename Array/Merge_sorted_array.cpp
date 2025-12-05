// LeetCode #88: merge sorted array
// https://leetcode.com/problems/merge-sorted-array#in
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++){
            nums1[m]=nums2[i];
            m++;
        }
        sort(nums1.begin(),nums1.end());
        
    }
};