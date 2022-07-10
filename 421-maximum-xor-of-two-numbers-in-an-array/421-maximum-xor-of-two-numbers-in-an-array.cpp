class node{
  public:
    int data;
    unordered_map<int,node*> children;
    
    node(int d){
        data = d;
    }
};

class trie{
  public:
    node *root;
    trie(){
        root = new node(2);
    }
    
    void insert(int n){
        node *head = root;
        for(int i=31;i>=0;i--){
            if(((n>>i)&1)==0){
                if(head->children.count(0)){
                    head = head->children[0];
                }
                else{
                    node *n = new node(0);
                    head->children[0] = n;
                    head = n;
                }
            }
            else{
                if(head->children.count(1)){
                    head = head->children[1];
                }
                else{
                    node *n = new node(1);
                    head->children[1] = n;
                    head = n;
                }
            }
        }
    }
    
    int find(int n){
        int ans = 0;
        node *head = root;
        
        for(int i=31;i>=0;i--){
            if(((n>>i)&1)==0){
                if(head->children.count(1)){
                    head = head->children[1];
                    ans += pow(2,i);
                }
                else{
                    head = head->children[0];
                }
            }
            else{
                if(head->children.count(0)){
                    head = head->children[0];
                    ans += pow(2,i);
                }
                else{
                    head = head->children[1];
                }
            }
        }
        
        return ans;
    }    
};

class Solution {
public:
    int findMaximumXOR(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        
        trie t;
        
        for(int i=0;i<n;i++){
            t.insert(v[i]);
            int cur = t.find(v[i]);
            ans = max(ans,cur);
        } 
        
        return ans;
    }
};