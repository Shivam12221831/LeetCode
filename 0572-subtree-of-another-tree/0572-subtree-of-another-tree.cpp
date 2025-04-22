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
    bool isIdentical(TreeNode* h1, TreeNode* h2){
        if(h1==NULL || h2==NULL) return h1==h2;
        bool isLeftSame = isIdentical(h1->left, h2->left);
        bool isRightSame = isIdentical(h1->right, h2->right);
        return isLeftSame && isRightSame && h1->val==h2->val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL || subRoot==NULL) return root==subRoot;
        if(root->val == subRoot->val && isIdentical(root, subRoot)){
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};