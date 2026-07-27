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
    vector<int> inorderTraversal(TreeNode* root) {
        //intializing an empty result and an empty stack
        vector<int> myResult;
        stack<TreeNode*> myStack;
        TreeNode* current = root;

        while(current or !myStack.empty())
        {
            while(current)
            {
                myStack.push(current);
                current = current->left;
            }
            current = myStack.top();
            myStack.pop();
            myResult.push_back(current->val);
            current = current->right;
        }
        return myResult;
    }
};