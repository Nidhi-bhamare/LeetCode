#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int maxLen = 0;
        int prevCount = 0;
        int i = 0;

        while (i < nums.size()) {
            int currVal = nums[i];
            int count = 0;

            // count how many times currVal appears
            while (i < nums.size() && nums[i] == currVal) {
                count++;
                i++;
            }

            // check if previous value was currVal - 1
            if (i > count && nums[i - count - 1] == currVal - 1) {
                maxLen = max(maxLen, count + prevCount);
            }

            prevCount = count;
        }

        return maxLen;
    }
};
