class Solution {

    
public:
long long reqHours(vector<int>nums, int hours){
        long long sum=0;
    
        for(int i=0;i<nums.size();i++){
            sum+= ceil((double)nums[i]/(double)hours);
        }
        return sum;
    }

int findMax(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        
        // Find the maximum element
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }

int minEatingSpeed(vector<int>&nums, int h) {
    int low =1; 
    int high = findMax(nums);
    while(low<=high){
        long long mid = (low+high)/2;
        long long reqTime = reqHours(nums,mid);
        if(reqTime<=h){
            high = mid-1;
        }
        else low = mid+1;
    }
    return low;
    }
};
