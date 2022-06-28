class Solution {
public:
    int minDeletions(string &s) {
        priority_queue<int> pq;
        vector<int> mp(26,0);
        int n = s.size();
        
        for(int i=0;i<n;i++){
            // cout<<(s[i]-'a')<<endl;
            mp[(s[i]-'a')]++;
        }
        
        int ans = 0;
        for(char ch='a';ch<='z';ch++){
            if(mp[(ch-'a')]>0){
                pq.push(mp[(ch-'a')]);
            }
        }
        
        // return ans;
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