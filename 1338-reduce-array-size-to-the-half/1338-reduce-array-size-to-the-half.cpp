class Solution {
public:
    int minSetSize(vector<int>& v) {
        int n = v.size();
        // map<int,int> mp;
        int ans = 0;
        
        vector<int> mp(100001,0);
        
        for(int i=0;i<n;i++){
            mp[v[i]]++;
        }
        
        priority_queue<int> pq;
        
        for(auto x:mp){
            if(x>0){
                pq.push(x);
            }            
        }
        
        int cnt = n;
        
        while(cnt>(n/2)){
            int cur = pq.top();
            pq.pop();
            
            cnt-=cur;
            ans++;
        }
        
        
        return ans;
    }
};