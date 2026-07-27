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
        //in order to do this we're going to use a new list and a stack
        vector<int> myResult;
        stack<TreeNode*> myStack;
        //we also need a pointer to keep up on track
        TreeNode* current = root;

        //now while we are traversing the graph we need to stop when its empty
        //current just equals current!=nullptr
        while(current or !myStack.empty())
        {
            //then we're going to start traversing the left side since inorder is left, root, right
            while(current)
            {
                //we need to push everything from the top to the stack
                myStack.push(current);
                current = current->left;
            }
            //now after hitting the limit of the left we need to reput this back into our result list
            //first we need to get the top
            current = myStack.top();
            //then push it into the result;
            myResult.push_back(current->val);
            //and then pop the top
            myStack.pop(); 
            current = current->right;
        }
        return myResult;
    }
};