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
    vector<int> rightSideView(TreeNode* root) {
        //use a bfs on this which chooses you to go visit every level
        //create a queue and a result array to put the reuslts in
        vector<int> result;
        queue<TreeNode*> q; 
        q.push(root);
    

        //now traverse the queue when its not empty
        while(!q.empty())
        {
            //whne you traverese this queue, you want to be able to add in each level
            int qLength = q.size();
            //you want to be able to track the right side as well
            TreeNode* rightSide = nullptr; //set to null ptr so you can just update

            for(int i = qLength; i > 0; --i)
            {
                //you are able to traverse the legnths and you want to pop and push into queue and keep track
                TreeNode* node = q.front();
                // and then you're able to pop
                q.pop();
            
                if(node)
                {
                    //if node is not nullptr then you want to first mark the right side as this node
                    rightSide = node;
                    //then push the children into the queue
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(rightSide)
            {
                result.push_back(rightSide->val);
            }

        }
        return result;
    }
};
