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
        if(root->val==t->val){
            return root;
        }
        
        if(root->left){
            TreeNode* temp = getTargetCopy(o,root->left,t);
            if(temp!=NULL){
                return temp;
            }
        }

        if(root->right){
            TreeNode* temp = getTargetCopy(o,root->right,t);
            if(temp!=NULL){
                return temp;
            }
        }
        
        return NULL;
    }
};