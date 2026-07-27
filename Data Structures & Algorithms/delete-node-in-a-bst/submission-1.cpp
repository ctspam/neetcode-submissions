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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //there are 3 main cases for this, always start with base case 
        //base case
        if(!root)
        {
            return root;
        }

        if(root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        //3 cases if equal to
        else
        {
            //if no left child
            if(!root->left)
            {
                return root->right;
            }
            else if(!root->right)
            {
                return root->left;
            }
            else
            {
                //this is for two children
                //we need to make a pointer to delete it recursively
                TreeNode *current = root->right;
                //you want to make it efficient and look for the min on the right root, to replace
                while(current->left)
                {
                    current = current->left;
                }
                root->val = current->val; //this replaces the value of the root with teh current->val
                root->right = deleteNode(root->right, current->val); //replaces every right with the current value recursiveley

            }
        }
        return root;

    }
};