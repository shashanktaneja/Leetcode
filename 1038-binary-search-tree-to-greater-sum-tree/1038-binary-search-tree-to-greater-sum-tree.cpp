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
    int sum;
    
    void solve(TreeNode* root){
        if(root==NULL){
            return;
        } 
        
        solve(root->right);
        int cur = root->val;
        root->val += sum;
        sum += cur;
        solve(root->left);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        sum = 0;
        solve(root);
        
        return root;
    }
};