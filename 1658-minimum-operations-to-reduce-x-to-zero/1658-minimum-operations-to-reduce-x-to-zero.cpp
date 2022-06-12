class Solution {
public:
    int minOperations(vector<int>& v, int &k) {
        int ans = INT_MAX;
        vector<int> pre,suff;
        int n = v.size();
        
        pre.push_back(v[0]);
        
        for(int i=1;i<n;i++){
            pre.push_back((pre[i-1]+v[i]));
        }
        
        suff.push_back(v[n-1]);
        
        for(int i=n-2;i>=0;i--){
            suff.push_back((suff[n-i-2]+v[i]));
        }
        
        reverse(suff.begin(),suff.end());
        
        for(int i=0;i<n;i++){
            int cur = pre[i];
            if(cur==k){
                ans = min(ans,i+1);
                break;
            }
            else{
                int idx = -1;
                int req = (k-pre[i]);
                if(req<=0){
                    break;
                }
                int s=i+1,e=n-1;
                while(s<=e){
                    int mid = (s+e)/2;
                    if(suff[mid]==req){
                        idx = mid;
                        break;
                    }
                    else if(suff[mid]<req){
                        e = mid-1;
                    }
                    else{
                        s = mid+1;
                    }
                }
                
                if(idx!=-1){
                    int cur = (i+1)+(n-idx);
                    ans = min(ans,cur);
                }
            }
        }
        
        for(int i=n-1;i>=0;i--){
            int cur = suff[i]; 
            if(cur==k){
                ans = min(ans,n-i);
                break;
            }
            else{
                int idx = -1;
                int req = (k-suff[i]);
                if(req<=0){
                    break;
                }
                int s=0,e=i-1;
                while(s<=e){
                    int mid = (s+e)/2;
                    if(pre[mid]==req){
                        idx = mid;
                        break;
                    }
                    else if(pre[mid]>req){
                        e = mid-1;
                    }
                    else{
                        s = mid+1;
                    }
                }
                
                if(idx!=-1){
                    int cur = (idx+1)+(n-i);
                    ans = min(ans,cur);
                }
            }
        }        
        
        if(ans==INT_MAX){
            return -1;
        }
        
        return ans;
    }
};