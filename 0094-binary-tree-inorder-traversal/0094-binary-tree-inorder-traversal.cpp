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
    // void inorder(TreeNode* root,vector<int>& ans){
    //     if(root==NULL){
    //         return; 
    //     }
    //     inorder(root->left,ans);
    //     ans.push_back(root->val);
    //     inorder(root->right,ans);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // inorder(root,ans);
        // return ans;
        
        
        vector<int> inorder;
        TreeNode *curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr=curr->right;
            }else{
                TreeNode* pre=curr->left;
                while(pre->right&&pre->right!=curr){
                    pre=pre->right;
                }
                if(pre->right==NULL){
                    pre->right=curr;
                    curr=curr->left;
                }else{
                    pre->right=NULL;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
            
        }
        return inorder;
        
    }
};