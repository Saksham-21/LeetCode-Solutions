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
    bool isSymmetricUtil(TreeNode* l,TreeNode* r){
        if(l==NULL ||r==NULL){
            return l==r;
        }
        return (l->val==r->val) && isSymmetricUtil(l->left, r->right) && isSymmetricUtil(r->left, l->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSymmetricUtil(root->left, root->right);
    }
};