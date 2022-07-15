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
    int left(TreeNode* root){
        int ht = 1;
        while(root->left!=NULL){
            ht++;
            root=root->left;
        }
        
        return ht;
    }
    
    int right(TreeNode* root){
        int ht = 1;
        while(root->right!=NULL){
            ht++;
            root=root->right;
        }
        
        return ht;
    }
    
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int l=left(root);
        int r = right(root);
        
        if(l==r){
            return (1<<l)-1;
        }
        
        int left = solve(root->left);
        int right = solve(root->right);
                
        return left+right+1;
    }
    
    int countNodes(TreeNode* root) {
        int ans = solve(root);
                
        return ans;
    }
};