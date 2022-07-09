class node{
  public:
    int data;
    unordered_map<char,node*> children;
    bool terminal;
    
    node(int d){
        data = d;
        terminal = false;
    }
};

class Trie {
public:
    node *root;
    
    Trie() {
        root = new node('\0');
    }
    
    void insert(string s) {
        int n = s.size();
        node *head = root;
        for(int i=0;i<n;i++){
            char cur = s[i];
            if((head->children.count(cur))>0){
                head = head->children[cur];
            }
            else{
                node *n = new node(cur);
                head->children[cur] = n;
                head = n;
            }
        }
        
        head->terminal = true;        
    }
    
    bool search(string s) {
        int n = s.size();
        node *head = root;
        
        for(int i=0;i<n;i++){
            char cur = s[i];
            if(head->children.count(cur)){
                head = head->children[cur];
            }
            else{
                return false;
            }
        }
        
        if(head->terminal){
            return true;
        }
        
        return false;
    }
    
    bool startsWith(string s) {
        int n = s.size();
        node *head = root;
        
        for(int i=0;i<n;i++){
            char cur = s[i];
            if(head->children.count(cur)){
                head = head->children[cur];
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */