class Solution {
private:
    // Helper function to merge and count reverse pairs
    void merge(vector<int>& nums, int low, int mid, int high, int& reversePairsCount) {
        int j = mid + 1;
        
        // Count reverse pairs
        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }
            reversePairsCount += (j - (mid + 1));
        }
        
        // Merge the two halves
        vector<int> temp(high - low + 1);
        int left = low, right = mid + 1, k = 0;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp[k++] = nums[left++];
            } else {
                temp[k++] = nums[right++];
            }
        }

        while (left <= mid) {
            temp[k++] = nums[left++];
        }
        while (right <= high) {
            temp[k++] = nums[right++];
        }

        // Copy sorted elements back to the original array
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    // Recursive merge sort function
    void mergeSort(vector<int>& nums, int low, int high, int& reversePairsCount) {
        if (low >= high) return;

        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid, reversePairsCount);
        mergeSort(nums, mid + 1, high, reversePairsCount);
        merge(nums, low, mid, high, reversePairsCount);
    }

public:
    int reversePairs(vector<int>& nums) {
        int reversePairsCount = 0;
        mergeSort(nums, 0, nums.size() - 1, reversePairsCount);
        return reversePairsCount;
    }
};