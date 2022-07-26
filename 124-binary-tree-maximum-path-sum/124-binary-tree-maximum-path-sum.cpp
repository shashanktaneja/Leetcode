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
    int solve(TreeNode* root){
        if(root==NULL)
            return 0;
        
        int lst = solve(root->left);
        int rst = solve(root->right);
        
        int op1 = lst+rst+root->val;
        int op2 = lst+root->val;
        int op3 = rst+root->val;
        int op4 = root->val;
        
        int cur = max(op1,max(op2,max(op3,op4)));
        ans = max(ans,cur);
        return max(0,max(lst,rst))+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        solve(root);
        
        return ans;
    }
};