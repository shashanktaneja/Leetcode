class Solution {
public:
    vector<int> v;
    int k=0;
    int n;
    
    Solution(vector<int>& w) {
        v.clear();
        priority_queue<pair<int,int>> tp;
        n = w.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += w[i];
            tp.push({w[i],i});
        }
        k=0;
        
        while(!tp.empty()){
            pair<int,int> cur = tp.top();
            tp.pop();
            
            int ti = ((cur.first)*100)/sum;
            for(int j=0;j<ti;j++){
                v.push_back(cur.second);
            }
            
            if(ti==0 and cur.first!=0){
                v.push_back(cur.second);
            }
        }      
        
        n = v.size();
    }
    
    int pickIndex() {
        int ans = v[k];
        k = (k+1)%n;
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */