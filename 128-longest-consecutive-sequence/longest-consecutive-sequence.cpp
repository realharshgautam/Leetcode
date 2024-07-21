class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        int leastSmall = INT_MIN;
        int longest =1;
        int cnt=0;

        for(int i =0; i<nums.size();i++){
            if((nums[i]-1)==leastSmall){
                cnt++;
                leastSmall = nums[i];
            }
            else if(nums[i]!=leastSmall){
                cnt = 1;
                leastSmall = nums[i];
            }
            longest = max(cnt,longest);
        }
       return longest; 
    }
};