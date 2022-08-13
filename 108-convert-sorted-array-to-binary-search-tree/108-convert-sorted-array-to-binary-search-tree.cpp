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
    TreeNode* solve(int s,int e,vector<int> &v){
        if(s>e){
            return NULL;
        }
        
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = solve(s,mid-1,v);
        root->right = solve(mid+1,e,v);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& v) {
        int n = v.size();
        TreeNode* root = solve(0,n-1,v);
        
        return root;
    }
};