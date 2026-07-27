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
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }

private:
    void inorder(TreeNode* node, int& k, int& ans) {
        if (!node || k == 0) return;   // stop if done or null

        inorder(node->left, k, ans);

        if (--k == 0) {               // visit node
            ans = node->val;
            return;
        }

        inorder(node->right, k, ans);
    }
};
