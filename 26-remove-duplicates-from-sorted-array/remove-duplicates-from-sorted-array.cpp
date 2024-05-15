class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0;
        int n = nums.size();
        for(int j =1;j<n;j++){
            if(nums[i]!=nums[j]){
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;
        
    }
};