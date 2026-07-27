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
    int kthSmallest(TreeNode* root, int k) 
    {
        /**
        you can use arrays since its hsorter amount of codes but that'd be o(n)
        nicer to use stacks and for dfs in a bst since its in order
        this will have a time complexity of o(h+k) = o(h)
        */

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
            --k;
            if(k == 0)
            {
                return current->val;
            }
            current = current->right;
        }
    }
};
