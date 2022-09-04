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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int> > ans;

        queue<pair<TreeNode*, int>>q;
        map<int, vector<int> > m;

        int min_index = 0;
        int max_index = 0;

        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            vector<pair<int,int>>v;
            
            while(size--){
                pair<TreeNode*, int> p = q.front();
                q.pop();

                TreeNode *f = p.first;
                int index = p.second;
                v.push_back({f->val,index});

                min_index = min(index, min_index);
                max_index = max(index, max_index);

                if (f->left) {
                    q.push({f->left, index - 1});
                }

                if (f->right) {
                    q.push({f->right, index + 1});
                }
            }   
            
            sort(v.begin(),v.end());
            for(auto x:v){
                m[x.second].push_back(x.first);
            }
            
        }
        
        for(int i=min_index;i<=max_index;i++){
            ans.push_back(m[i]);
        }
        
        return ans;
    }
};