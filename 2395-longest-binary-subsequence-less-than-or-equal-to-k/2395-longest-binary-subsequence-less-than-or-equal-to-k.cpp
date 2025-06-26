class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int count = 0;           // count of valid bits
        long long value = 0;     // binary value being formed
        long long power = 1;     // 2^0 to 2^i

        // Traverse from right to left
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                count++;         // Always include 0
                if (power <= k) power <<= 1;
            } else {
                if (power > k) continue; // 2^i > k → can't include
                if (value + power <= k) {
                    value += power;
                    count++;
                    power <<= 1;
                }
            }
        }
        return count;
    }
};
