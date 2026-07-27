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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //since the results are going level by level, we can use BFS on this 
        //make sure to always have htis, if the tree is empty, return an empty list
        vector<vector<int>> result;
        if(!root)
        {
            return result;
        }
        //you'd want to push the root into the queu
        //repeatdly remove nodes from the queue, which form the current levl
        //add their children into the queue, forming the next levle
        //continue until the queue is empty
        queue<TreeNode*> myQueue;
        myQueue.push(root); //push the firrst root in

        while(!myQueue.empty())
        {
            vector<int> level;
            int size = myQueue.size();

            for(int i = size; i > 0; --i)
            {
                TreeNode* node = myQueue.front();
                myQueue.pop();
                if(node)
                {
                    level.push_back(node->val);
                    myQueue.push(node->left);
                    myQueue.push(node->right);
                }
            }
            if(!level.empty())
            {
                result.push_back(level);
            }
        }
        return result;

    }
};
