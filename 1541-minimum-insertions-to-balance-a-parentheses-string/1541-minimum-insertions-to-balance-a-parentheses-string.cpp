class Solution {
public:
    int minInsertions(string s) {

        int low = 0, result = 0, n = s.size();
        int cnt = 0;
        while (low < n) {
            if (s[low] == '(') {
                cnt += 1;
                low += 1;
            } else {
                if (cnt > 0) {
                    cnt -= 1;
                } else {
                    result += 1;
                }

                if (low+1<n && s[low + 1] == ')') {
                    low += 2;
                } else {
                    result += 1;
                    low += 1;
                }
            }
        }
        return result+cnt*2;
    }
};