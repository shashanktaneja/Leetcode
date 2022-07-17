typedef long long ll;

class Solution {
public:
    int mod = 1e9+7;
    
    int sumSubarrayMins(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        stack<int> s;
        s.push(0);
        vector<pair<ll,ll>> tp(n,{1,1});
        
        for(int i=1;i<n;i++){
            while(!s.empty() and v[i]<v[s.top()]){
                s.pop();
            }
            
            if(s.empty()){
                tp[i].first = i+1;
            }
            else{
                tp[i].first = i-s.top();
            }
            
            s.push(i);
        }
        
        while(!s.empty()){
            s.pop();
        }
        
        s.push(n-1);
        
        for(int i=n-2;i>=0;i--){
            while(!s.empty() and v[i]<=v[s.top()]){
                s.pop();
            }
            
            if(s.empty()){
                tp[i].second = n-i;
            }
            else{
                tp[i].second = s.top()-i;
            }
            
            s.push(i);
        }
        
        for(int i=0;i<n;i++){
            ans = (((ans)%mod)+((v[i]*tp[i].first*tp[i].second)%mod))%mod;
        }
        
        
        return ans;
    }
};