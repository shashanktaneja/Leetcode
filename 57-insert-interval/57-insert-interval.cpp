class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& t) {
        int n = v.size();        
        vector<vector<int>> ans;
        
        if(n==0){
            ans.push_back(t);
            return ans;
        }
        
        if(t[0]>v[n-1][1]){
            v.push_back(t);
            return v;
        }
        
        if(t[1]<v[0][0]){
            v.insert(v.begin(),t);
            return v;
        }
        
        int i=1;
        
        while(i<n){
            if(t[0]>v[i-1][1] and t[1]<v[i][0]){
                v.insert(v.begin()+i,t);
                return v;
            }
            
            if(t[0]>=v[i][0] and t[1]<=v[i][1]){
                return v;
            }
            i++;
        }
        
        i=0;
        
        while(i<n){
            if(t[0]<=v[i][1]){
                if(t[0]<v[i][0]){
                    v[i][0] = t[0];
                }
                
                if(t[1]>v[i][1]){
                    v[i][1] = t[1];
                }
                
                ans.push_back(v[i]);
                i++;
                while(i<n){
                    if(ans[ans.size()-1][1]<v[i][0]){
                        break;
                    }
                    
                    if(ans[ans.size()-1][1]>=v[i][1]){
                        i++;
                    }
                    else{
                        ans[ans.size()-1][1] = v[i][1];
                        i++;
                        break;
                    }
                }
                
                while(i<n){
                    ans.push_back(v[i]);
                    i++;
                }
                
                return ans;
            }
            ans.push_back(v[i]);
            i++;
        }
        
        return ans;
    }
};