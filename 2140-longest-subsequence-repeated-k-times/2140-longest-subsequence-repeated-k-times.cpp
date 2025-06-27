class Solution {
public:
    // Check if t*k is a subsequence of s
    bool isKSubsequence(const string& s, const string& t, int k) {
        int i = 0, cnt = 0;
        for (char c : s) {
            if (c == t[i]) {
                i++;
                if (i == t.size()) {
                    cnt++;
                    if (cnt == k) return true;
                    i = 0; // reset for next t
                }
            }
        }
        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        // Count characters
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        // Use only characters appearing at least k times
        string valid_chars = "";
        for (char c = 'z'; c >= 'a'; --c) {
            if (freq[c] >= k)
                valid_chars += c;
        }

        queue<string> q;
        q.push("");
        string ans = "";

        // BFS with pruning: generate strings from longest to shortest
        while (!q.empty()) {
            string curr = q.front(); q.pop();

            for (char c : valid_chars) {
                string next = curr + c;

                if (isKSubsequence(s, next, k)) {
                    // Update answer if longer or lexicographically larger
                    if (next.size() > ans.size() || (next.size() == ans.size() && next > ans)) {
                        ans = next;
                    }
                    q.push(next);
                }
            }
        }
        return ans;
    }
};
