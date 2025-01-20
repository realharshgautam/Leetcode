class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int count =0;
        for(int i=0; i<nums.size();i++){
            if(count == 0){
                ele = nums[i];
                count++;
            }
            else if(nums[i] == ele){
                count++;
            }
            else{
                count--;
            }
        }
        return ele;
    }
};