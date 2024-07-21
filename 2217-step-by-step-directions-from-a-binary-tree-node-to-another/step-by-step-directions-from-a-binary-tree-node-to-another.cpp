class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        string path {}, startPath {}, endPath {};
        postOrder(root, startValue, path, startPath); path.clear();
        postOrder(root, destValue, path, endPath); path.clear();

        string res {};
        int go_up = startPath.size();
        int i {};
        for (i=0; i<startPath.size() && i < endPath.size() && startPath[i] == endPath[i]; ++i)
            --go_up;
        res += string(go_up, 'U');
        for (int j=i; j<endPath.size(); ++j) res += endPath[j];
        return res;
    }
private:
    string startPath {};
    string endPath {};
    void postOrder(TreeNode* root, int val, string& path, string& result){
        if (!root || !result.empty()) return;
        if (root->val == val){
            result = path;
            return;
        }
        
        path += 'L';
        postOrder(root->left, val, path, result);
        path.pop_back();

        path +='R';
        postOrder(root->right, val, path, result);
        path.pop_back();
    }
};