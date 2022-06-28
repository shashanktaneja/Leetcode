class Solution {
public:
    int minDeletions(string &s) {
        priority_queue<int> pq;
        vector<int> mp(26,0);
        int n = s.size();
        
        for(int i=0;i<n;i++){
            mp[(s[i]-'a')]++;
        }
        
        int ans = 0;
        for(auto x:mp){
            if(x>0){
                pq.push(x);                
            }
        }
        
        int lt = pq.top();
        pq.pop();
        
        while(!pq.empty()){
            int cur = pq.top();
            pq.pop();
            
            if(lt!=cur){
                lt = cur;
                continue;
            }
            
            ans++;
            if(cur-1>0){
                pq.push(cur-1);
            }
        }        
        
        return ans;
    }
};