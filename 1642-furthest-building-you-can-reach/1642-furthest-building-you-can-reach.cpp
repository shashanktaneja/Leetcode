class Solution {
public:
    int furthestBuilding(vector<int>& v, int &b, int &l) {
        int n = v.size();
        int ans = 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        int i=1;
        while(i<n and l>0){
            if(v[i]-v[i-1]<=0){
                i++;
                continue;
            }
            pq.push((v[i]-v[i-1]));
            i++;
            l--;
        }
        
        while(i<n){
            if(v[i]-v[i-1]<=0){
                i++;
                continue;
            }
            
            pq.push((v[i]-v[i-1]));
            int mi = pq.top();
            pq.pop();
            
            if(b>=mi){
                b-=mi;
                i++;
            }
            else{
                return i-1;
            }
        }
        
        return i-1;
    }
};