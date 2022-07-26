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
    bool solve(TreeNode *root,TreeNode* k,vector<TreeNode*> &p){
        if(root==NULL){
            return false;
        }
        
        p.push_back(root);
        
        if(root==k){
            return true;
        }
        
        // p.push_back(root);
        
        if((root->left and solve(root->left,k,p)) || (root->right and solve(root->right,k,p))){
            return true;
        }
        
        p.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p1,p2;
        solve(root,p,p1);
        solve(root,q,p2);
        
        TreeNode* ans;
        int i=0;
        
        while(i<p1.size() and i<p2.size() and p1[i]==p2[i]){
            ans = p1[i];
            i++;
        }
        
        return ans;
    }
};