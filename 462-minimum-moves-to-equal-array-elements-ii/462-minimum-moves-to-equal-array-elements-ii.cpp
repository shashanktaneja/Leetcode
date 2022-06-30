class Solution {
public:
    int minMoves2(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        int s=0,m=0;
        sort(v.begin(),v.end());
        
        if(n%2!=0){
            m = v[n/2];
        }
        else{
            m = ((v[(n/2)-1]+v[n/2])/2);
        }
        
        for(int i=0;i<n;i++){
            ans += abs(m-v[i]);
        }
        
        return ans;
    }
};