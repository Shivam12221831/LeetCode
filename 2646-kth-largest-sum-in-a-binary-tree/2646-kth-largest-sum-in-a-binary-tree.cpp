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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        vector<long long> levelSums;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            long long level = 0;

            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                level += curr->val;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            levelSums.push_back(level);
        }

        sort(levelSums.begin(), levelSums.end());

        if(k > levelSums.size()){
            return -1;
        } else {
            return levelSums[levelSums.size()-k];
        }
    }
};