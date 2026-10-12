class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long res = 0;
            for (auto num : piles) {
                res += (num + mid - 1) / mid;
            }

            if (res <= h) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
};