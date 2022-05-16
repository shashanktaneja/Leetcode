class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& v) {
        int n = v.size();
        if(v[0][0]==1){
            return -1;
        }
        else if(n==1){
            return 1;
        }
        
        queue<pair<int,pair<int,int>>> q;
        bool vis[n][n];
        q.push({0,{0,1}});
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                vis[i][j]=false;
            }
        }
        
        vis[0][0] = true;
        int dx[8] = {1,1,0,-1,-1,-1,0,1};
        int dy[8] = {0,-1,-1,-1,0,1,1,1};
        
        while(!q.empty()){
            pair<int,pair<int,int>> cur = q.front();
            q.pop();
            
            for(int i=0;i<8;i++){
                int nx = cur.first+dx[i];
                int ny = cur.second.first+dy[i];
                int dis = cur.second.second;
                
                if(nx>=0 and ny>=0 and nx<n and ny<n and v[nx][ny]==0 and !vis[nx][ny]){
                    vis[nx][ny] = true;
                    q.push({nx,{ny,dis+1}});
                    
                    if(nx==n-1 and ny==n-1){
                        return dis+1;
                    }
                }
            }
        }            
        
        return -1;
    }
};