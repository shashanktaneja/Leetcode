class Solution {
public:
    vector<int> v;
    vector<pair<int,int>> tp;
    int n;
    int k=0;
    int si;
    
    Solution(vector<int>& w) {
        v.clear();
        tp.clear();
        n = w.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += w[i];
            tp.push_back({w[i],i});
        }
        
        sort(tp.begin(),tp.end(),greater<pair<int,int>>());
        k=0;
        
        for(int i=0;i<n;i++){
            int ti = ((tp[i].first)*100)/sum;
            for(int j=0;j<ti;j++){
                v.push_back(tp[i].second);
            }
            
            if(ti==0 and tp[i].first!=0){
                v.push_back(tp[i].second);
            }
        }      
        
        si = v.size();
    }
    
    int pickIndex() {
        int ans = v[k];
        k = (k+1)%si;
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */