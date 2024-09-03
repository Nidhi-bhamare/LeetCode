class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& nums, int e) {
        int mx=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>mx){
                mx=nums[i];
            }
        }
        vector<bool> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+e<mx){
                ans.push_back(0);
            }else{
                ans.push_back(1);
            }
        }
        return ans;
    }
};