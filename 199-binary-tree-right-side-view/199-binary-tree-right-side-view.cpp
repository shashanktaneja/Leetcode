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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        
        queue<pair<TreeNode*,int>> q;
        ans.push_back(root->val);
        
        q.push({root,0});
        int l = 0;
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<TreeNode*,int> p = q.front();
                q.pop();
                
                if(p.second>l){
                    l = p.second;
                    ans.push_back(p.first->val);
                }
                
                if(p.first->right){        
                    q.push({p.first->right,p.second+1});
                }  
                
                if(p.first->left){
                    q.push({p.first->left,p.second+1});
                }             
            }
            
        }
        
        
        
        return ans;
    }
};