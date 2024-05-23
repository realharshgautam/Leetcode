class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        count = 0;
        explore(nums, k, 0);
        return count - 1; // Subtract 1 to exclude the empty subset
    }

private:
    int count;
    unordered_map<int, int> visited;

    void explore(vector<int>& nums, int k, int index) {
        if (index == nums.size()) {
            count++;
            return;
        }

        int num = nums[index];

        if (visited.find(num - k) == visited.end() &&
            visited.find(num + k) == visited.end()) {
            visited[num]++;
            explore(nums, k, index + 1);
            visited[num]--;
            if (visited[num] == 0) {
                visited.erase(num);
            }
        }

        explore(nums, k, index + 1);
    }
};