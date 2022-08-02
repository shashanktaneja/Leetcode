class Solution {
public:
    typedef pair<int,pair<int,int>> custompair;
    
    int kthSmallest(vector<vector<int>>& mat, int k) {
      int n = mat.size();
      priority_queue<custompair,vector<custompair>,greater<custompair>> pq;
      for(int i=0;i<n;i++){
          pq.push({mat[0][i],{0,i}});
      }

      int ans = -1;
      while(k--){
          ans = pq.top().first;
          int x = pq.top().second.first;
          int y = pq.top().second.second;
          pq.pop();

          if(x+1<n){
            pq.push({mat[x+1][y],{x+1,y}});
          }
      }
        
        return ans;
    }
};