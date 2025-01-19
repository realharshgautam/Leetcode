class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map <int, int> hash;

        
        for(int i=0;i<n;++i){
            int num = nums[i];
            int complement = target - num;
            if(hash.find(complement)!=hash.end()){
                return{hash[complement], i};
            }
            hash[num] =i;
        }       
        return {};
        }
    
};