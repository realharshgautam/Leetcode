class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Find the intersection point of the two pointers
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Find the entrance of the cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};