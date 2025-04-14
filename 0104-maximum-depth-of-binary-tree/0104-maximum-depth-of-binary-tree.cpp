class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> que;
        que.push(root);
        int level = 0;

        while (!que.empty()) {
            int size = que.size();
            while (size-- > 0) {
                TreeNode* rem = que.front();
                que.pop();

                if (rem->left != nullptr) {
                    que.push(rem->left);
                }
                if (rem->right != nullptr) {
                    que.push(rem->right);
                }
            }
            level++;
        }

        return level;
    }
};
