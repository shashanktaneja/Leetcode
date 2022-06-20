bool compare(string &s1,string &s2){
    return s1.size()>s2.size();
}

class node{
  public:
    char data;
    unordered_map<char,node*> children;
    
    node(char d){
        data = d;
    }
};

class trie{
public:
    node *root;
    trie(){
        root = new node('\0');
    }
    
    void insert(string &s){
        int n = s.size();
        node *temp = root;
        for(int i=0;i<n;i++){
            char cur = s[i];
            if(temp->children.count(cur)){
                temp = temp->children[cur];
            }
            else{
                node* n = new node(cur);
                temp->children[cur] = n;
                temp = n;
            }
        }
    }
    
    bool find(string &s){
        int n = s.size();
        node *temp = root;
        
        for(int i=0;i<n;i++){
            char cur = s[i];
            if(temp->children.count(cur)){
                temp = temp->children[cur];
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& v) {
        int n = v.size();
        string ans = "";
        sort(v.begin(),v.end(),compare);
        trie t;
        for(int i=0;i<n;i++){
            reverse(v[i].begin(),v[i].end());
        }
        
        for(int i=0;i<n;i++){
            int si = v[i].size();
            bool val = false;
            
            if(t.find(v[i])==false){
                ans += v[i];
                ans+="#";
                t.insert(v[i]);
            }
        }        
        
        return ans.size();
    }
};