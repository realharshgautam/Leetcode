class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int count =0;
        for(auto it : nums){
            if(count == 0){
                ele = it;
                count++;
            }
            else if(it == ele){
                count++;
            }
            else{
                count--;
            }
        }
        return ele;
    }
};