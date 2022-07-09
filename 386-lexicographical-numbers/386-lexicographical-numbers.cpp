class Solution {
public:
    vector<int> ans;
    
    void solve(int cur,int &n){
        if(cur>n){
            return;
        }
        
        ans.push_back(cur);
        for(int j=0;j<10;j++){
            solve(10*cur+j,n);
        }
    }
    
    vector<int> lexicalOrder(int &n) {
        ans.clear();
        for(int i=1;i<10;i++){
            solve(i,n);
        }
        
        return ans;
    }
};