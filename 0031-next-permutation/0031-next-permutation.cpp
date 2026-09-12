class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int min_ind = -1;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                min_ind = i - 1;
                break;
            }
        }

        if (min_ind != -1) {
            int max_ind = min_ind;

            for (int j = n - 1; j >= min_ind + 1; j--) {
                if (nums[j] > nums[min_ind]) {
                    max_ind = j;
                    break;
                }
            }
            swap(nums[max_ind], nums[min_ind]);
        }

        reverse(nums.begin() + min_ind + 1, nums.end());
    }
};