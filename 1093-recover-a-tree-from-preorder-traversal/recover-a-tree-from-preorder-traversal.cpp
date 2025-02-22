/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
        TreeNode* recoverFromPreorder(string S) {
        vector<TreeNode*> stack;
        for (int i = 0, level, val; i < S.length();) {
            for (level = 0; S[i] == '-'; i++)
                level++;
            for (val = 0; i < S.length() && S[i] != '-'; i++)
                val = val * 10 + S[i] - '0';
            TreeNode* node = new TreeNode(val);
            while (stack.size() > level) stack.pop_back();
            if (!stack.empty())
                if (!stack.back()->left) stack.back()->left = node;
                else stack.back()->right = node;
            stack.push_back(node);
        }
        return stack[0];
    }
};