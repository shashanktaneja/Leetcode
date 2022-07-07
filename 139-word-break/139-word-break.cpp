class node{
  public:
    char data;
    map<char,node*> children;
    bool terminal;
    node(char d){
        data = d;
        terminal = false;
    }
};

class trie{
  public:
    node *root;
    trie(){
        root = new node('\0');
    }
    
    void insert(string &w){
        int n = w.size();
        // cout<<w<<endl;
        node *head = root;
        for(int i=0;i<n;i++){
            char cur = w[i];
            // cout<<cur<<endl;
            if(head->children.count(cur)){
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
    
    bool find(string &w){
        int n = w.size();
        node *head = root;
        int i=0;
        
        while(i<n){
            char cur = w[i];
            if(head->children.count(cur)>0){
                head = head->children[cur];
            }
            else{
                return false;
            }
            
            i++;
        }
        
        if(head->terminal){
            return true;
        }
        
        return false;
    }
    
};

class Solution {
public:    
    int dp[304][304];
    
    bool solve(int i,int n,string &s,trie *t){
        if(i==n){
            return true;
        }
        
        if(dp[i][n]!=-1){
            return dp[i][n];
        }
        
        for(int j=i;j<n;j++){
            string cur = s.substr(i,j-i+1);
            if(t->find(cur)){
                if(solve(j+1,n,s,t)){
                    return dp[i][n] = true;
                }
            }
        }
        
        return dp[i][n] = false;
    }
    
    bool wordBreak(string &s, vector<string>& v) {
        int n = v.size();
        trie *t = new trie();
        
        for(int i=0;i<n;i++){
            t->insert(v[i]);
        }
        
        memset(dp,-1,sizeof(dp));
        int si = s.size();
        
        bool ans = solve(0,si,s,t);
        return ans;
    }
};