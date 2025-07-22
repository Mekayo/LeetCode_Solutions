// LeetCode #735: Asteroid Collision
// https://leetcode.com/problems/asteroid-collision


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            }
            // this condition follows when get to the left moving asteroid  
            else {
                // Asteroid is moving left
                while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) {
                    st.pop();
                }
                if (!st.empty() && st.top() == abs(asteroids[i])) {
                    // Same size collision
                    st.pop();
                } else if (st.empty() || st.top() <= 0) {
                    // No collision or top is also negative
                    st.push(asteroids[i]);
                }
            }
        }
        vector<int> ans(st.size());
        for(int i=(int)st.size()-1;i>=0;--i){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};
