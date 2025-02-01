class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        /*
        -4 -1 -1 0 1 2
        */
        vector<vector<int>> ans;
        

        for(int i=0;i<nums.size();i++){
            int left = i+1; int right = nums.size()-1;
            if(nums[i]>0) continue;
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];

                if(sum < 0){
                    left++;
                }else if(sum > 0 ){
                    right--;
                }else{
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++,
                    right--;

                    while(left < right && nums[left] == nums[left-1]){
                        left++;
                    }
                }
            }
        }

        return ans;
    }
};