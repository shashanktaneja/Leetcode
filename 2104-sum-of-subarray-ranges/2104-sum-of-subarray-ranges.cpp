typedef long long ll;

class Solution {
public:
    long long subArrayRanges(vector<int>& v) {
        int n = v.size();
        ll ma = 0,mi = 0;
        
        vector<pair<ll,ll>> tp(n, {1,1});
        stack<int> s;
        s.push(0);
        
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
                // cout<<s.top()<<" "<<i<<" "<<tp[i].second<<endl;
            }            
            
            s.push(i);
        }
        
        for(int i=0;i<n;i++){
            // cout<<tp[i].first<<" "<<tp[i].second<<endl;
            mi += (v[i]*(tp[i].first*tp[i].second));
        }
        
        while(!s.empty()){
            s.pop();
        }
        
        s.push(0);
        
        for(int i=1;i<n;i++){
            while(!s.empty() and v[i]>v[s.top()]){
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
            while(!s.empty() and v[i]>=v[s.top()]){
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
            // cout<<tp[i].first<<" "<<tp[i].second<<endl;
            ma += (v[i]*(tp[i].first*tp[i].second));
        }
        
        // cout<<mi<<" "<<ma<<endl;
        
        return ma-mi;
    }
};