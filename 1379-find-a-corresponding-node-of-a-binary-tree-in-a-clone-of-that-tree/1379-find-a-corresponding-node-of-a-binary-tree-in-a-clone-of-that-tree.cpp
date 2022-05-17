/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:    
    TreeNode* getTargetCopy(TreeNode* &o, TreeNode* &root, TreeNode* &t) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            
            if(cur->val==t->val){
                return cur;
            }
            
            if(cur->left){
                q.push(cur->left);
            }
            
            if(cur->right){
                q.push(cur->right);
            }
        }
        
        return NULL;
    }
};