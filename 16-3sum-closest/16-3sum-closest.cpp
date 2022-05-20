class Solution {
public:
    int threeSumClosest(vector<int>& v, int t) {
        int n =v.size();
        int ans;
        int cur = INT_MAX;
        
        sort(v.begin(),v.end());
        
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int s = j+1,e = n-1;
                int tp = v[i]+v[j];
                while(s<=e){
                    int mid = (s+e)/2;                    
                    if(tp+v[mid]<t){
                        s = mid+1;
                    }
                    else{
                        e = mid-1;
                    }
                    
                    if(cur>abs(tp+v[mid]-t)){
                        cur = abs(tp+v[mid]-t);
                        ans = tp+v[mid];
                    }
                }
            }
        }
        
        return ans;
    }
};