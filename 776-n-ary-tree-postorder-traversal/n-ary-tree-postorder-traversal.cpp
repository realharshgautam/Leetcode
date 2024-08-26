class Solution {
public:
    vector<int> postorder(Node* root) {
        // If the root is null, return an empty vector
        if (!root) return {};

        vector<int> res;

        // Define the DFS function
        function<void(Node*)> dfs = [&](Node* node) {
            // Recursively call dfs for each child of the current node
            for (Node* child : node->children) {
                dfs(child);
            }
            // Append the value of the current node to the result vector
            res.push_back(node->val);
        };

        // Start DFS from the root
        dfs(root);

        // Return the result vector containing node values in post-order
        return res;
    }
};