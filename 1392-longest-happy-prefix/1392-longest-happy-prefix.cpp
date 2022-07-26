class Solution {
public:
    string longestPrefix(string &s) {
        int len = 0;
        int si = 0;
        int n = s.size();
        vector<int> lps(n,0);
        
        int i=1;
        while(i<n){
            // cout<<i<<endl;
            if(s[i]==s[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len>0){
                    len = lps[len-1];
                }
                else{
                    i++;
                }
            }
        }
        
        // for(int i=0;i<n;i++){
        //     si=max(si,lps[i]);
        // }
        
        si = lps[n-1];
        
        string ans = s.substr(0,si);
            
        return ans;
    }
};