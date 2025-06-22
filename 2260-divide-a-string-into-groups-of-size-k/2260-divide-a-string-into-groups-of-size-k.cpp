class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int n = s.length();

        for (int i = 0; i < n; i += k) {
            string temp = "";

            // k characters भरतो, जर शेवटचे कमी असतील तर fill करतो
            for (int j = i; j < i + k && j < n; j++) {
                temp += s[j];
            }

            // जर temp ची लांबी कमी असेल, तर fill letter टाकतो
            while (temp.length() < k) {
                temp += fill;
            }

            result.push_back(temp);
        }

        return result;
    }
};
