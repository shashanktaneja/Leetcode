/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* &root) {
        queue<Node*> q;
        q.push(root);
        
        if(root==NULL){
            return root;
        }
        
        while(!q.empty()){
            int si = q.size();
            int cur = q.size();
            while(si--){
                Node* tp = q.front();
                q.pop();
                cur--;
                if(tp->left){
                    q.push(tp->left);
                }
                
                if(tp->right){
                    q.push(tp->right);
                }
                
                if(cur==0){
                    tp->next = NULL;
                    break;
                }
                
                tp->next = q.front();  
            }
        }
                
        return root;
    }
};