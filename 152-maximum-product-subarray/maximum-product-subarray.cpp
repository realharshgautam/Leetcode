class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int pre =1, suff =1;
        for(int i =0; i<nums.size();++i){
            if(suff ==0)suff=1;
            if(pre ==0)pre=1;
            pre *= nums[i];
            suff *= nums[nums.size()-i-1];
            maxi =max(maxi, max(pre,suff));
        }
        return maxi;
    }
};