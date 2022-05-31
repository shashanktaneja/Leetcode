class Solution {
public:
    bool hasAllCodes(string &s, int k) {
        int n = s.size();
        if(k>n){
            return false;
        }
        
        string tp = s.substr(0,k);
        map<int,int> mp;
        int hash = 0;
        int pos = 1;
        
        for(int i=tp.size()-1;i>=0;i--){
            if(tp[i]=='1'){
                hash += pos;
            }
            pos*=2;
        }
        
        mp[hash]++;        
        int req = (1<<k);
        
        for(int i=k;i<n;i++){
            hash = (hash<<1);
            hash = (hash&(req-1));
            int cur = (s[i]-'0');
            hash |= cur;
            
            mp[hash]++;
            if(mp.size()==req){
                return true;
            }
        }
                
        return false;
    }
};