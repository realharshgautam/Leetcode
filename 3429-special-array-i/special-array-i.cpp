class Solution {
public:
    static bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return 1;
        bool prev=nums[0]&1;
        for (int i=1; i<n; i++){
            bool x=nums[i]&1;
            if (x^prev==0) return 0;
            prev=x;
        }
        return 1;
    }
};