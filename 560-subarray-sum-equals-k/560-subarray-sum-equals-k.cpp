class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        int n = v.size();
        int ans = 0;
        
        int pre = 0;
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++){
            pre+=v[i];
            if(pre==k){
                ans++;
            }
            
            if(mp.find(pre-k)!=mp.end()){
                ans += mp[pre-k];
            }
            
            mp[pre]++;
        }
        
        
        
        return ans;
    }
};