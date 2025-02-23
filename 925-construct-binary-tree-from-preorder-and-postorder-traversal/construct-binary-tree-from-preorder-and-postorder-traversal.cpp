class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int numOfNodes = preorder.size();
        return constructTree(0, numOfNodes - 1, 0, preorder, postorder);
    }

private:
    // Helper function to construct the tree recursively
    TreeNode* constructTree(int preStart, int preEnd, int postStart,
                            vector<int>& preorder, vector<int>& postorder) {
        // Base case: If there are no nodes to process, return NULL
        if (preStart > preEnd) return NULL;

        // Base case: If only one node is left, return that node
        if (preStart == preEnd) {
            return new TreeNode(preorder[preStart]);
        }

        // The left child root in preorder traversal (next element after root)
        int leftRoot = preorder[preStart + 1];

        // Calculate the number of nodes in the left subtree by searching in
        // postorder
        int numOfNodesInLeft = 1;
        while (postorder[postStart + numOfNodesInLeft - 1] != leftRoot) {
            numOfNodesInLeft++;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        // Recursively construct the left subtree
        root->left = constructTree(preStart + 1, preStart + numOfNodesInLeft,
                                   postStart, preorder, postorder);

        // Recursively construct the right
        root->right =
            constructTree(preStart + numOfNodesInLeft + 1, preEnd,
                          postStart + numOfNodesInLeft, preorder, postorder);

        return root;
    }
};