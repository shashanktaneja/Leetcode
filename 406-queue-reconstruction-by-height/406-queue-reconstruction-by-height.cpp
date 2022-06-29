bool compare(vector<int> &v1, vector<int> &v2){
    return v1[1]<v2[1];
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& v) {
        int n = v.size();
        vector<vector<int>> ans;
        sort(v.begin(),v.end(),compare);
        ans.push_back(v[0]);
        
        for(int i=1;i<n;i++){
            int cnt = v[i][1];
            int no = v[i][0];
            
            int j=0;
            int tp = 0;
            int idx = ans.size();
            while(j<ans.size()){
                if(tp==cnt and ans[j][0]>=no){
                    idx = j;
                    break;
                }
                
                if(ans[j][0]>=no){
                    tp++;
                }
                
                j++;
            }
            
            ans.insert(ans.begin()+idx,v[i]);
        }
                        
        return ans;
        
        
        
//         map<int,vector<vector<int>>> mp;
        
//         for(int i=0;i<n;i++){
//             mp[v[i][1]].push_back(v[i]);
//         }
        
//         for(auto x:mp){
//             vector<vector<int>> tp = x.second;
//             sort(tp.begin(),tp.end());
//             for(int i=0;i<tp.size();i++){
//                 ans.push_back(tp[i]);
//             }
//             // ans.push_back()
//         }
    }
};