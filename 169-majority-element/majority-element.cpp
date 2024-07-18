class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int el;
        int cnt =0;
        for(int i=0; i<n;i++){

        
        if(cnt == 0){
            el = nums[i];
        }
        if(nums[i] == el){
            cnt ++;
        }
        else{
            cnt --;} 
        }

        return el;
      

    }
};