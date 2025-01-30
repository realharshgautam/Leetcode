class Solution {
   public:
    int countStudents(vector<int> &nums, int pages) {
        int pagesStudent = 0;
        int student = 1;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (pagesStudent + nums[i] <= pages) {
                pagesStudent += nums[i];
            } else {
                student++;
                pagesStudent = nums[i];
            }
        }
            return student;
    }
    int splitArray(vector<int> &nums, int m) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(),0);

        while (low <= high) {
            int mid = (low + high) / 2;
            int students = countStudents(nums, mid);
            if (students > m) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
            return low;
    }
};