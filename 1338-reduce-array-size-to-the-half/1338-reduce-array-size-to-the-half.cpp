class Solution {
public:
    int minSetSize(vector<int>& v) {
        int n = v.size();
        map<int,int> mp;
        int ans = 0;
        
        for(int i=0;i<n;i++){
            mp[v[i]]++;
        }
        
        priority_queue<int> pq;
        
        for(auto x:mp){
            pq.push(x.second);
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