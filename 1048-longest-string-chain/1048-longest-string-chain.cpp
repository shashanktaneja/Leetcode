class Solution {
public:
    bool val(string &s1,string &s2){
        int n = s1.size();
        int m = s2.size();
        
        if((m-n)!=1){
            return false;
        }
        
        int i=0,j=0;
        while(i<m and j<n){
            if(s1[j]==s2[i]){
                j++;
            }
            i++;
        }
        
        if(j==n){
            return true;
        }
        
        return false;
    }
    
    int longestStrChain(vector<string>& v) {
        int n = v.size();
        int ans = 1;
        
        vector<int> dp(n,1);   
        vector<pair<int,string>> tp;
        
        for(int i=0;i<n;i++){
            tp.push_back({v[i].size(),v[i]});
        }
                
        sort(tp.begin(),tp.end());
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(val(tp[j].second,tp[i].second)){
                    dp[i] = max(dp[i],(dp[j]+1));
                }
            }
            ans = max(ans,dp[i]);
        }
                
        return ans;
    }
};