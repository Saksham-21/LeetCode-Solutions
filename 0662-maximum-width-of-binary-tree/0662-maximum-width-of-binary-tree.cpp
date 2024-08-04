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
int widthOfBinaryTree(TreeNode* root) {
    if(!root) return 0; // If root is null, return 0
    queue<pair<TreeNode*, long long>> q;
    q.push({root, 0}); // Push root with index 0
    long long ans = 0; // Initialize maximum width
    
    while(!q.empty()) {
        int size = q.size(); // Number of nodes at current level
        long long mmin = q.front().second; // Minimum index at current level
        long long first, last;
        
        for(int i = 0; i < size; i++) {
            long long curr_id = q.front().second - mmin; // Adjusted index
            TreeNode* node = q.front().first;
            q.pop();
            
            if(i == 0) first = curr_id; // First index at current level
            if(i == size - 1) last = curr_id; // Last index at current level
            
            if(node->left) q.push({node->left, 2 * curr_id + 1}); // Left child
            if(node->right) q.push({node->right, 2 * curr_id + 2}); // Right child
        }
        ans = max(ans, last - first + 1); // Update maximum width
    }
    
    return ans; // Return the maximum width
}

};