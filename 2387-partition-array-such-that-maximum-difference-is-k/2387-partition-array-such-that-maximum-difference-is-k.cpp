class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        //step 01-:sort the array
         sort(nums.begin(), nums.end());

         int count=1;//atleast one group needed
         int start=nums[0];// start of the first group




         //step 02-: Traverse the array from second element
         for (int i=1; i<nums.size();i++){
             // If the current number is out of allowed range (>k difference)
             if (nums[i]-start>k){
                count++; // Start a new group
                start=nums[i];// Update the start of this new group
             }
         }


   return count;



        
    }
};