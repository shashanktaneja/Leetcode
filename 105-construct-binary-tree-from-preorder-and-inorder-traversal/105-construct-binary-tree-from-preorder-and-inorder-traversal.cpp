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
    int i;
    map<int,int> m;
    
    TreeNode *build(vector<int>& inorder, vector<int>& preorder,int s,int e){
        
        if(s>e){
            return NULL;
        }
                
        TreeNode *root = new TreeNode(preorder[i]);
        
        int index = m[preorder[i]];
        
        i++;
                
        root->left = build(inorder,preorder,s,index-1);
        root->right = build(inorder,preorder,index+1,e);
        
        return root;
                
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        
        i = 0;
        
        for(int a=0;a<n;a++){
            m[inorder[a]] = a;
        }
        
        TreeNode *root = build(inorder,preorder,0,n-1);
        
        return root;  
    }
};