class Solution {
public:
    int furthestBuilding(vector<int>& v, int b, int l) {
        int n = v.size();
        int ans = 0;
        int s=0,e=n-1;
        vector<int> tp;
        for(int i=0;i<n-1;i++){
            if(v[i]-v[i+1]<0){
                tp.push_back((-v[i]+v[i+1]));
            }
            else{
                tp.push_back(0);
            }
        }
        
        while(s<=e){
            int mid = (s+e)/2;
            bool val = false;
            
            int j=l,k=b;
            priority_queue<int> pq;
            for(int i=0;i<mid;i++){
                pq.push(tp[i]);
            }
            
            while(!pq.empty()){
                int cur = pq.top();
                
                if(cur==0){
                    pq.pop();
                    continue;
                }
                
                if(j>0){
                    j--;
                    pq.pop();
                }
                else if(k>=cur){
                    pq.pop();
                    k-=cur;
                }
                else{
                    break;
                }
            }
            
            if(pq.empty()){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        
        return ans;
    }
};