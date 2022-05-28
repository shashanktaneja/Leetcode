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
    vector<vector<int>> ans;
    
    void solve(int s,TreeNode* &root,int t,vector<int> v){
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL and root->right==NULL){
            if(s+root->val==t){
                v.push_back(root->val);
                ans.push_back(v);
                v.pop_back();
            }
            return;
        }
        
        v.push_back(root->val);
        solve(s+root->val,root->left,t,v);

        solve(s+root->val,root->right,t,v);
        v.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* &root, int t) {
        ans.clear();
        vector<int> v;
        solve(0,root,t,v);        
        return ans;
    }
};