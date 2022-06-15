bool compare(string &s1,string &s2){
    return s1.size()<s2.size();
}

class Solution {
public:
    int longestStrChain(vector<string>& v) {
        int n = v.size();
        int ans = 1;        
        unordered_map<string,int> dp;
                
        sort(v.begin(),v.end(),compare);
        
        for(int i=0;i<n;i++){
            string word = v[i];
            dp[word] = 1;
            
            for(int j=0;j<v[i].size();j++){
                string cur = word.substr(0,j)+word.substr(j+1);
                if(dp.find(cur)!=dp.end()){
                    dp[word] = max(dp[word],dp[cur]+1);
                }
            }
            
            ans = max(ans,dp[word]);
        }
                
        return ans;
    }
};