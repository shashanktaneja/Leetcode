class Solution {
public:
    int wiggleMaxLength(vector<int>& v) {
        int n = v.size();
        int ans = 1;
        int i=1;
        
        while(i<n and v[i]==v[i-1]){
            i++;
        }
        
        while(i<n){
            if(i==n-1){
                ans++;
                break;
            }
            
            if(v[i]>v[i-1]){
                while(i<n and v[i]>=v[i-1]){
                    i++;
                }
                ans++;
            }
            else{
                while(i<n and v[i]<=v[i-1]){
                    i++;
                }
                ans++;
            }
        }
                
        return ans;
    }
};