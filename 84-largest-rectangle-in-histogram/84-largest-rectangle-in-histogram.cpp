class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        stack<int> s;
        vector<pair<int,int>> tp(n,{0,0});
        s.push(0);
        
        for(int i=1;i<n;i++){
            while(!s.empty() and v[i]<=v[s.top()]){
                s.pop();
            }
            
            if(s.empty()){
                tp[i].first = i;
            }
            else{
                tp[i].first = i-s.top()-1;
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
                tp[i].second = n-i-1;
            }
            else{
                tp[i].second = s.top()-i-1;
            }
            
            s.push(i);
        }
        
        for(int i=0;i<n;i++){
            int cur = v[i]*(tp[i].first+tp[i].second+1);
            ans = max(ans,cur);
        }
                
        return ans;
    }
};