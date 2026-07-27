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
        Initialize an empty stack and set curr = root.
        While either stack is not empty or curr is not null:
        Push all left nodes into the stack (curr = curr.left).
        Pop from the stack - this is the next smallest node.
        Decrement k. If k == 0, return that node's value.
        Move to the right subtree (curr = curr.right).
        The popped k-th node is the answer.
        */

        int n = 0; 
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
            ++n;
            if(n == k)
            {
                return current->val;
            }
            current = current->right;
        }
    }
};
