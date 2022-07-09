class Solution {
public:
    int maxResult(vector<int>& v, int k) {
        int n = v.size();
        vector<int> dp(n,0);
        dp[0] = v[0];
        int ma = v[0];
        deque<int> q;
        q.push_back(0);
        
        for(int i=1;i<k;i++){
            if(i==n){
                break;
            }
            
            int cur = dp[q.front()]+v[i];
            
            while(!q.empty() and cur>=dp[q.back()]){
                q.pop_back();
            }
            
            q.push_back(i);            
            dp[i] = cur;
        }
        
        for(int i=k;i<n;i++){
            int cur = dp[q.front()]+v[i];
            
            while(!q.empty() and cur>=dp[q.back()]){
                q.pop_back();
            }
            
            q.push_back(i);            
            dp[i] = cur;
            
            if(q.front()<=i-k){
                q.pop_front();   
            }            
        }
               
        
        return dp[n-1];
    }
};