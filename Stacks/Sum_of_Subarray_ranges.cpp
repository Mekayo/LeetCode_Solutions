// LeetCode #2104: Sum of subarray ranges
// https://leetcode.com/problems/sum-of-subarray-ranges


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// sum of min values
     long long  Mins(vector<int>& arr) {
         
        int n = arr.size();
        
        vector<long long> left(n), right(n);
        stack<pair<int, int>> s1, s2;

        //  extended left 
        for (int i = 0; i < n; ++i) {
            int count = 1;
            while (!s1.empty() && s1.top().first > arr[i]) {
                count += s1.top().second;
                s1.pop();
            }
            s1.push({arr[i], count});
            left[i] = count;
        }
        // extended right
        for (int i = n - 1; i >= 0; --i) {
            int count = 1;
            
            while (!s2.empty() && s2.top().first >= arr[i]) {
                count += s2.top().second;
                s2.pop();
            }
            s2.push({arr[i], count});
            right[i] = count;
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long contribution = (arr[i] * left[i] * right[i]);
            ans = (ans + contribution);
        }

        return ans;
    }
// sum of max values
     long long Maxs(vector<int>& arr) {
       
        int n = arr.size();
        
        vector<long long> left(n), right(n);
        stack<pair<int, int>> s1, s2;

        //  extended left 
        for (int i = 0; i < n; ++i) {
            int count = 1;
            while (!s1.empty() && s1.top().first < arr[i]) {
                count += s1.top().second;
                s1.pop();
            }
            s1.push({arr[i], count});
            left[i] = count;
        }
        // extended right
        for (int i = n - 1; i >= 0; --i) {
            int count = 1;
            
            while (!s2.empty() && s2.top().first <= arr[i]) {
                count += s2.top().second;
                s2.pop();
            }
            s2.push({arr[i], count});
            right[i] = count;
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long contribution = (arr[i] * left[i] * right[i]) ;
            ans = (ans + contribution)  ;
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        
        long long ma=Maxs(nums);
        long long mi=Mins(nums);
        return ma-mi;
    }
};