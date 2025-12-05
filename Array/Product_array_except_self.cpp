// LeetCode #238: product of array except self
// https://leetcode.com/problems/product-of-array-except-self

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
          int n=nums.size();

        vector<int> ans(n,1);//prefix array
          
            int leftproduct=1;
        for(int i=0;i<n;i++){
            ans[i]*=leftproduct;
            leftproduct*=nums[i];
        }
        int rightproduct=1;
        for(int j=n-1;j>=0;j--){
            ans[j]*=rightproduct;
            rightproduct*=nums[j];
                         
        }
    return ans;
  }
};
 