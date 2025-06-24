class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
         vector<int> result;
         vector<int> keyIndices;

         for(int j=0;j<nums.size(); ++j){
            if (nums[j]==key){
                keyIndices.push_back(j);
            }
         }

         for (int i=0;i<nums.size(); ++i){
            for(int j:keyIndices){
                if(abs(i-j)<=k){
                    result.push_back(i);
                    break;
                }
            }
         }

         return result;

      }
};