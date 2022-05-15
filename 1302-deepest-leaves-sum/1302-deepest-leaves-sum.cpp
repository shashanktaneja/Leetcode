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
    int cnt;
    int ans;
    
    void dfs1(int cur,TreeNode* &root){
        if(root->left==NULL and root->right==NULL){
            if(cnt<cur){
                cnt = cur;
            }
            return;
        }
        
        if(root->left){
            dfs1(cur+1,root->left);
        }
        
        if(root->right){
            dfs1(cur+1,root->right);
        }
    }
    
    void dfs2(int cur,TreeNode* &root){
        if(root->left==NULL and root->right==NULL){
            if(cur==cnt){
                ans+=(root->val);
            }
            return;
        }
        
        if(root->left){
            dfs2(cur+1,root->left);
        }
        
        if(root->right){
            dfs2(cur+1,root->right);
        }
    }
    
    int deepestLeavesSum(TreeNode* &root) {
        cnt = INT_MIN,ans = 0;
        dfs1(0,root);
        dfs2(0,root);
        
        return ans;
    }
};