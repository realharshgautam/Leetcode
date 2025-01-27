class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int low =0, high = nums.size()-1;
       int ans = nums.size();
       while(low<=high){
        
        int mid = low + (high-low)/2;
        if(nums[mid]>= target){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
       }
       return ans;
    }

};