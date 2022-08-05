class dsu{
  public:
    int *parent;
    int *rank;
    int n;
    
    dsu(int v){
        parent = new int[v];
        rank = new int[v];
        n = v;
        
        for(int i=0;i<v;i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    
    int find(int i){
        if(parent[i]==-1){
            return i;
        }
        
        return parent[i] = find(parent[i]);
    }
    
    void unite(int x,int y){
        int s1 = find(x);
        int s2 = find(y);
        
        if(s1!=s2){
            parent[s2] = s1;
            rank[s1]+=rank[s2];
        }
    }
};

bool contain_cycle(vector<vector<int>> &v,int idx){
    int n = v.size();
    dsu s(n+1);
    
    for(int i=0;i<n;i++){
        if(i==idx){
            continue;
        }
        
        int s1 = s.find(v[i][0]);
        int s2 = s.find(v[i][1]);
        
        if(s1!=s2){
            s.unite(v[i][1],v[i][0]);
        }
        else{
            return true;
        }
    }

    return false;
}

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> ans;
        int indegree[n+1];
        memset(indegree,0,sizeof(indegree));
        bool val = true;
        
        for(int i=0;i<n;i++){
            indegree[v[i][1]]++;
            if(indegree[v[i][1]]==2){
                val = false;
                break;
            }
        }
        
        if(val){        
            dsu s(n+1);
            //indegree is 1 so check cycle
            for(int i=0;i<n;i++){
                int s1 = s.find(v[i][0]);
                int s2 = s.find(v[i][1]);
                
                if(s1!=s2){
                    s.unite(v[i][1],v[i][0]);
                }
                else{
                    ans = {v[i][0],v[i][1]};
                    break;
                }
            }            
        }
        else{
            //indegree is 2
            int i=0,idx1,idx2;
            while(i<n){
                if(indegree[v[i][1]]==2){
                    idx1 = i;
                    i++;
                    break;
                }
                i++;
            }
            
            while(i<n){
                if(indegree[v[i][1]]==2){
                    idx2 = i;
                    i++;
                    break;
                }
                i++;
            }
            
            if(contain_cycle(v,idx2)){
                ans = v[idx1];
            }
            else{
                ans = v[idx2];
            }
        }
        
        return ans;
    }
};