class node{
  public:
    char data;
    unordered_map<char,node*> children;
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
    
    void insert(string &s){
        int n = s.size();
        node* head = root;
        
        for(int i=0;i<n;i++){
            char cur = s[i];
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
    
    bool find(string &s){
        int n = s.size();
        node* head = root;
        
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

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
vector<string> ans;
int vis[13][13];

void dfs(int x,int y,int &n,int &m,node *root,string s,vector<vector<char>>&v){    
    if(root->terminal){
        root->terminal = false;
        ans.push_back(s);
    }
    
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0 and ny>=0 and nx<m and ny<n and vis[nx][ny]==0 and (root->children.count(v[nx][ny]))){
            s+=v[nx][ny];
            vis[nx][ny] = 1;
            dfs(nx,ny,n,m,root->children[v[nx][ny]],s,v);
            vis[nx][ny] = 0;
            s.pop_back();
        }
    }
    
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& v, vector<string>& v2) {
        int m = v.size();
        int n = v[0].size();
        trie *t = new trie();
        ans.clear();
        
        for(int i=0;i<v2.size();i++){
            t->insert(v2[i]);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                string tp = "";
                node* head = t->root;
                if(head->children.count(v[i][j])){
                    memset(vis,0,sizeof(vis));
                    vis[i][j] = 1;
                    tp+=v[i][j];
                    head = head->children[v[i][j]];
                    dfs(i,j,n,m,head,tp,v);
                }
            }
        }
        
        return ans;
    }
};