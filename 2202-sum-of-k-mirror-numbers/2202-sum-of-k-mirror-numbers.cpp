class Solution {
public:
    // Helper to convert number to base-k string
    string toBaseK(long long num, int k) {
        string res = "";
        while (num > 0) {
            res = char('0' + num % k) + res;
            num /= k;
        }
        return res;
    }

    // Helper to check if a string is palindrome
    bool isPalindrome(const string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    // Main function
    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;

        for (int length = 1; count < n; length++) {
            int start = pow(10, (length - 1) / 2);
            int end = pow(10, (length + 1) / 2);

            for (int i = start; i < end; i++) {
                string s = to_string(i);
                string rev = s;
                reverse(rev.begin(), rev.end());
                string palStr = s + (length % 2 ? rev.substr(1) : rev); // odd/even length
                long long num = stoll(palStr);

                if (isPalindrome(toBaseK(num, k))) {
                    sum += num;
                    count++;
                    if (count == n) return sum;
                }
            }
        }

        return sum;
    }
};
