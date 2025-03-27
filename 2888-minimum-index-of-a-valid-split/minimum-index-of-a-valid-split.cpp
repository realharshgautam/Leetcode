class Solution {
public:
    int minimumIndex(vector<int>& nums) {
    //find the majority element 
    int majority = nums[0], count = 0;
    for(auto n: nums){
        if(n == majority) count++;
        else count--;
        if(count == 0) { majority = n; count = 1; }
    }
    
    //count majority elements occurance
    int majCout = 0;
    for(auto n: nums) if(n == majority)  majCout++;
    
    //check if split is possible or not
    count = 0;
    for(int i = 0; i < nums.size(); ++i){
        if(nums[i] == majority) count++;
        if(count*2 > (i+1)  && (majCout - count)*2 > (nums.size() - i - 1)) return i;
    }
    return -1;
}
};