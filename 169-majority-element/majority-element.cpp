



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele, cnt=0;
        for(auto x:nums)
        {
            if(cnt ==0)
            {
                ele = x;
                cnt++;
            }
            else if(x == ele)
                cnt++;
            else
                cnt--;
        }

        return ele;
    }
};