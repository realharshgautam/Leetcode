class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<long long>> temp(n, vector<long long>(2, -1)); // temp[current_index(node)][is_even]
        
        return calculateMax(nums, n, k, 0, 1, temp);
    }

private:
    // calculate_max -> cur_ind -> cur_index of the tree and is_even represents whether we have already changed (XOR) even or odd number of nodes 
    long long calculateMax(vector<int>& nums, int n, int k, int curInd, int isEven, vector<vector<long long>>& temp) {
        if (curInd == n) {  // if we go to node which doesn't exist
            return isEven == 1 ? 0 : LLONG_MIN;
        }
        if (temp[curInd][isEven] != -1) {  // if we've already encountered this state
            return temp[curInd][isEven];
        }

        // checking all possible variants (no XOR or XOR)
        long long noXor = nums[curInd] + calculateMax(nums, n, k, curInd + 1, isEven, temp);  // we don't change the number of XOR nodes
        long long withXor = (nums[curInd] ^ k) + calculateMax(nums, n, k, curInd + 1, !isEven, temp);  // we added 1 XORed node

        long long mxPossible = max(noXor, withXor);
        temp[curInd][isEven] = mxPossible;
        return mxPossible;
    }
};