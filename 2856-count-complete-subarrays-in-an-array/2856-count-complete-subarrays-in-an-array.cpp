class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>uniqueElements(nums.begin(), nums.end());
        int totalUnique= uniqueElements.size();

        unordered_map<int, int> freq;
        int left=0, count=0;

        for(int right=0; right<n; ++right){
            freq[nums[right]]++;
            while(freq.size()== totalUnique){
                count +=(n-right);

                freq[nums[left]]--;
                if(freq[nums[left]]==0)
                freq.erase(nums[left]);
                left++;
            }
        }
        return count;
    }
};