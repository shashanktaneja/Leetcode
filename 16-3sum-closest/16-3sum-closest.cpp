class Solution {
public:
    int threeSumClosest(vector<int>& v, int &t) {
        int n = v.size();
        int ans;
        int cur = INT_MAX;
        
        sort(v.begin(),v.end());
        
        for(int j=0;j<n-2;j++){
            int s = j+1,e = n-1;
            while(s<e){                
                int tp = v[s]+v[e]+v[j];
                int gp = abs(tp-t);
                
                if(gp<cur){
                    cur = gp;
                    ans = tp;
                }
                
                if(tp<t){
                    s++;
                }
                else{
                    e--;
                }                
            }
        }        
        
        return ans;
    }
};