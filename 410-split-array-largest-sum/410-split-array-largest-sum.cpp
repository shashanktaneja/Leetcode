class Solution {
public:
    bool valid(int sum,vector<int> &v,int m,int n){
        int cur = 0;
        int cnt = 0;
        int i=0;
        
        while(i<n){
            if(cur+v[i]>sum){
                if(cnt+1>=m){
                    return false;
                }
                cur = 0;
                cnt++;
            }
            else{
                cur += v[i];
                i++;
            }
        }
        
        // if(cnt<m){
        //     return false;
        // }
        
        return true;
    }
    
    int splitArray(vector<int>& v, int m) {
        int n = v.size();
        int ans = INT_MAX;
        
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += v[i];
        }
        
        int s=0,e=sum;
        while(s<=e){
            int mid = (s+e)/2;
            if(valid(mid,v,m,n)){
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