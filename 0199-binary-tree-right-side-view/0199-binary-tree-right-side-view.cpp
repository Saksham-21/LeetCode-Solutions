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
        if(!root) return {};
        map<int,int> nodes;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* root=p.first;
            int x=p.second;
            if(nodes.find(x)==nodes.end()){
                nodes[x]=(root->val);   
            }
            if(root->right){
                q.push({root->right,x+1});
            }
            if(root->left){
                q.push({root->left,x+1});
            }
        }
        vector<int> ans;
        for(auto p:nodes){
            ans.push_back(p.second);
        }
        return ans;
    }
};