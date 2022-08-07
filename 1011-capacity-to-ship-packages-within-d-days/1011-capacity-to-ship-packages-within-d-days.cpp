class Solution {
public:
    bool valid(int wt,vector<int> &v,int k,int n){
        int cur = 0;
        int i=0;
        int d = 0;
        
        while(i<n){
            if(cur+v[i]>wt){
                if(d+1>=k){
                    return false;
                }
                cur = 0;
                d++;
            }
            else{
                cur += v[i];
                i++;
            }
        }
        
        return true;
    }
    
    int shipWithinDays(vector<int>& v, int k) {
        int n = v.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += v[i];
        }
        
        int s=0,e=sum;
        int ans;
        
        while(s<=e){
            int mid = (s+e)/2;
            if(valid(mid,v,k,n)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        
        
        return ans;
    }
};