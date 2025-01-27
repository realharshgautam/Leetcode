class Solution {
public:
    int lowerBound(vector<int>& nums, int target){
        int low = 0, high =nums.size()-1;
        int ans = nums.size();
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]>=target){
                ans=mid;
                high = mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }

    int upperBound(vector<int>& nums, int target){
        int low = 0, high =nums.size()-1;
        int ans = nums.size();
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]>target){
                ans=mid;
                high = mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums, target);
        if(lb==nums.size()||nums[lb]!=target) return{-1,-1};
        return{ lb, upperBound(nums,target)-1};        
    }
};