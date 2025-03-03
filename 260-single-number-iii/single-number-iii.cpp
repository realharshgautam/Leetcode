class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorr=0;
        for(int i =0; i<nums.size();i++) xorr^=nums[i];
        int rightmostbit = (xorr & xorr-1)^xorr;
        int b1=0, b2=0;
        for(int i =0; i<nums.size();i++){
            if(nums[i]&rightmostbit){
                b1^=nums[i];
            }
            else b2^=nums[i];
        }
        if(b1>b2) return{b2,b1};
        return {b1,b2};
    }
};