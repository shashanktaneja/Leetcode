class Solution {
public:
    map<string,vector<int>> mp;
    
    vector<int> solve(string s){
        if(mp.find(s)!=mp.end()){
            return mp[s];
        }
        
        vector<int> ans;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
                vector<int> left = solve(s.substr(0,i));
                vector<int> right = solve(s.substr(i+1));
                
                for(int j=0;j<left.size();j++){
                    for(int k=0;k<right.size();k++){
                        if(s[i]=='+'){
                            ans.push_back(left[j]+right[k]);
                        }
                        else if(s[i]=='-'){
                            ans.push_back(left[j]-right[k]);
                        }
                        else{
                            ans.push_back(left[j]*right[k]);
                        }
                    }
                }
            }            
        }
        
        if(ans.empty()){
            ans.push_back(stoi(s));
        }
        
        return mp[s] = ans;        
    }
    
    vector<int> diffWaysToCompute(string &s) {
        mp.clear();
        vector<int> ans = solve(s);   
        
        return ans;        
    }
};