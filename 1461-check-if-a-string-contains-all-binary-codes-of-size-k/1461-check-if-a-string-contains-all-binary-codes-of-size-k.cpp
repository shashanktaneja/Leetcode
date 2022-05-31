class Solution {
public:
    bool hasAllCodes(string &s, int k) {
        int n = s.size();
        if(k>n){
            return false;
        }
        
        string tp = s.substr(0,k);
        set<string> S;
        S.insert(tp);
        
        for(int i=1;i<n-k+1;i++){
            tp+=s[i+k-1];
            tp.erase(tp.begin());
            S.insert(tp);
        }
        
        int req = (1<<k);
        
        return S.size()>=req ? true : false;
    }
};