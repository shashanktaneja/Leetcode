class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& v, int t) {
        int m = v.size();
        int n = v[0].size();
        int ans = 0;
        
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                v[i][j] += v[i][j-1];
            }
        }
        
        for(int i=0;i<n;i++){
            for(int k=i;k<n;k++){    
                unordered_map<int,int> mp;
                int pre = 0;
                // mp[0] = 1;
                
                for(int j=0;j<m;j++){
                    pre+=v[j][k];
                    if(i>0){
                        pre-=v[j][i-1];
                    }
                    
                    if(pre==t){
                        ans++;
                    }

                    if(mp.find(pre-t)!=mp.end()){
                        ans += mp[pre-t];
                    }

                    mp[pre]++;
                }
            }
        }
        
        return ans;
    }
};