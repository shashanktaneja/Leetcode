class node{
  public:
    char data;
    bool terminal;
    unordered_map<char,node*> children;
    
    node(char d){
        data = d;
        terminal = false;
    }
};

bool val;

class trie{
  public:
    node* root;
    trie(){
        root = new node('\0');
    }
    
    void insert(string &s){
        int n = s.size();
        node* tp = root;
        for(int i=0;i<n;i++){
            char cur = s[i];
            if(tp->children.count(cur)){
                tp = tp->children[cur];
            }
            else{
                node *n = new node(cur);
                tp->children[cur] = n;
                tp = n;
            }
        }
        
        tp->terminal = true;
    }
    
    void dfs(node *tp, vector<string> &temp,string s){
        if(temp.size()==3){
            return;
        }
        
        char cur = tp->data;
        
        if(tp->terminal){
            s+=cur;
            temp.push_back(s);
            s.pop_back();
        }
        
        for(char ch = 'a';ch<='z';ch++){
            if(tp->children.count(ch)){
                s+=cur;
                dfs(tp->children[ch],temp,s);
                s.pop_back();     
            }
        }           
    }
    
    void find(vector<string> &temp, string &s){
        int n = s.size();
        node* tp = root;
        string s1 = "";
        
        for(int i=0;i<n;i++){
            char cur = s[i];
            s1 += cur;
            if(tp->children.count(cur)){
                tp = tp->children[cur];
            }
            else{
                val = false;
                return;
            }
        }
        
        s1.pop_back();
        dfs(tp,temp,s1);
    }    
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& v, string &t) {
        int n = v.size();
        int m = t.size();
        vector<vector<string>> ans;
        sort(v.begin(),v.end());
        trie T;
        
        int i=0;
        string cur = "";
        
        for(int i=0;i<n;i++){
            T.insert(v[i]);
        }
        
        for(int l=1;l<=m;l++){
            val = true;
            cur += t[l-1];
            vector<string> tp;
            T.find(tp,cur);   
            if(!val){
                ans.push_back(tp);
                continue;
            }
            ans.push_back(tp);
        }
                
        return ans;
    }
};