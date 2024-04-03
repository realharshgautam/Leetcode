class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        // storing no with their index so that we can get min index and max index
        unordered_map<int,int>mpp;

        for(int i = 0; i<nums.size(); i++){
            mpp[nums[i]] = i;
        }

        // now finding the minimum and maximum index
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        int minIndex = mpp[mini];
        int maxIndex = mpp[maxi];

        // three cases of deletion now
        // 1 case : deleting from left and right both sides
        int left = min(maxIndex, minIndex)+1;
        int right = nums.size() - max(maxIndex, minIndex);
        int tempAns1 = left+right;

        // 2 case : deletig both no from left size
        int tempAns2 = max(maxIndex, minIndex) + 1;

        // deleting both no from right size
        int tempAns3 = nums.size() - min(maxIndex, minIndex);

        return min({tempAns1, tempAns2, tempAns3});
    }
};