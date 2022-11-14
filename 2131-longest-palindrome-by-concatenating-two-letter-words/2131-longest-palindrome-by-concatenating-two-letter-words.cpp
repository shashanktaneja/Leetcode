class Solution {
public:
    int longestPalindrome(vector<string>& v) {
        int n = v.size();
        int ans = 0;
        bool val = false;
        
        map<string,int> mp;
        for(int i=0;i<n;i++){
            mp[v[i]]++;
        }
        
        for(auto x:mp){
            string cur = x.first;
            if(cur[0]==cur[1]){
                if((x.second)%2!=0){
                    val = true;
                }
                
                ans += 4*((x.second)/2);
                mp[x.first]=0;                
            }
            else{
                string tp = cur;
                reverse(tp.begin(),tp.end());
                if(mp[tp]>0){
                    int cnt = min(mp[cur],mp[tp]);
                    ans += (4*cnt);
                    mp[cur]-=(cnt);
                    mp[tp]-=cnt;
                }
            }
        }
        
        if(val){
            ans+=2;
        }
        
        return ans;
    }
};