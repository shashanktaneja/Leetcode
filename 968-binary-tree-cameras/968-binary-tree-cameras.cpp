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
    int ans;
    TreeNode* head;
    
    void solve(TreeNode* root){
        if(root->left==NULL and root->right==NULL){
            return;
        }
        
        if(root->left){
            solve(root->left);
        }
        
        if(root->right){
            solve(root->right);
        }
        
        bool val = false;
        int cnt = 0;
        
        if(root->left and (root->left->val)==0){
            val = true;
        }
        else if(root->left and (root->left->val)==1){
            cnt++;            
        }
        
        if(root->right and (root->right->val)==0){
            val = true;
        }
        else if(root->right and (root->right->val)==1){
            cnt++;            
        }
        
        if((root==head)){
            if((cnt==0) || val){
                root->val = 1;
                ans++;
            }
            return;
        }
        
        if(val){
            root->val = 1;
            ans++;
        }
        else if(cnt>0){
            root->val = 2;
        }
    }
    
    int minCameraCover(TreeNode* root) {
        if(root->left==NULL and root->right==NULL){
            return 1;
        }
        
        head = root;        
        ans = 0;
        solve(root);
        
        return ans;
    }
};