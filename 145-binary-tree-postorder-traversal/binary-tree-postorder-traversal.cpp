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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> list;
        help(list,root);
        return list;
    }
    void help(vector<int>& list,TreeNode* root){
        if(root==NULL){
            return;
        }
        help(list,root->left);
        help(list,root->right);
        list.push_back(root->val);
    }
};