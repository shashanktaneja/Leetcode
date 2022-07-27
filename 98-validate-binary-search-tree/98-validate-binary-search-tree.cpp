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
    bool solve(TreeNode*root,long long int mi,long long int ma){
        if(root==NULL){
            return true;
        }
        
        if(root->val>mi and root->val<ma and solve(root->left,mi,root->val) and solve(root->right,root->val,ma)){
            return true;
        }
        
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        long long int mi = INT_MIN,ma = INT_MAX;        
        mi--;
        ma++;
        
        bool ans = solve(root,mi,ma);
        
        return ans;
    }
};