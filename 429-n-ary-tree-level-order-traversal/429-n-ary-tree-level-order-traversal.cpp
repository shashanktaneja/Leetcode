/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* &root) {
        vector<vector<int>> ans;        
        if(root==NULL){
            return ans;
        }
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int si = q.size();
            vector<int> v;
            
            while(si--){
                Node* cur = q.front();
                q.pop();
                int tp = (cur->val);
                v.push_back(tp);
                for(auto nbr:(cur->children)){
                    q.push(nbr);
                }
            }
            
            ans.push_back(v);
        }
        
        return ans;
    }
};