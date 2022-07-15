class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        
        int ans = 0;
        bool vis[m+1][n+1];
        memset(vis,false,sizeof(vis));
        
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,-1,0,1};
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] and v[i][j]==1){
                    int cur = 0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j] = true;
                    
                    while(!q.empty()){
                        pair<int,int> tp = q.front();
                        q.pop();
                        cur++;
                        
                        for(int k=0;k<4;k++){
                            int nx = tp.first+dx[k];
                            int ny = tp.second+dy[k];
                            
                            if(nx>=0 and ny>=0 and nx<m and ny<n and !vis[nx][ny] and v[nx][ny]==1){
                                vis[nx][ny] = true;
                                q.push({nx,ny});
                            }
                        }
                    }
                    ans = max(ans,cur);
                }
            }
        }
        
        
        return ans;
    }
};