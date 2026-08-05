class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        for (auto num : intervals) {
            if (ans.empty() || ans.back()[1] < num[0])
                ans.push_back(num);

            else
                ans.back()[1] = max(ans.back()[1], num[1]);
        }
        return ans;
    }
};