class Solution {
public:
    int furthestBuilding(vector<int>& v, int &b, int &l) {
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
            
            int j=l,k=b;
            vector<int> pq;
            for(int i=0;i<mid;i++){
                pq.push_back(tp[i]);
            }
            sort(pq.begin(),pq.end(),greater<int>());
            int i=0;
            
            while(i<mid){
                int cur = pq[i];
                
                if(cur==0){
                    i++;
                    continue;
                }
                
                if(j>0){
                    j--;
                    i++;
                }
                else if(k>=cur){
                    i++;
                    k-=cur;
                }
                else{
                    break;
                }
            }
            
            if(i>=mid){
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