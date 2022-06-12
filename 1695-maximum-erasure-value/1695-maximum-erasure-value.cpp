class Solution {
public:
    int maximumUniqueSubarray(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        vector<int> mp(10001,0);
        
        int i=0,j=0;
        int sum = 0;
        
        while(j<n){
            if(mp[v[j]]>0){
                while(i<j and mp[v[j]]>0){
                    sum -= v[i];
                    mp[v[i]]--;
                    i++;
                }
            }
            
            sum += v[j];
            mp[v[j]]++;
            j++;
            ans = max(ans,sum);
        }
        
        return ans;
    }
};