bool compare(vector<int> &p1, vector<int> &p2){
    return p1[1]<p2[1];
}

class Solution {
public:    
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        int n = v.size();
        int cnt = 1;
        
        sort(v.begin(),v.end(),compare);        
        int i=1;
        int last = v[0][1];
        
        while(i<n){
            if(v[i][0]>=last){
                cnt++;
                last = v[i][1];
            }
            i++;
        }
        cnt = n-cnt;
        
        return cnt;
    }
};