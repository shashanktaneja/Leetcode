class Solution {
public:
    vector<vector<string>> ans;
    vector<string> v;
    
    bool valid(int i,int j,int n){
        int x=i-1,y=j-1;
        
        while(x>=0 and y>=0){
            if(v[x][y]=='Q'){
                return false;
            }
            x--;
            y--;
        }
        
        x=i-1,y=j+1;
        
        while(x>=0 and y<n){
            if(v[x][y]=='Q'){
                return false;
            }
            x--;
            y++;
        }
        
        return true;
    }
    
    void solve(int i,int mask,int n){
        if(i==n){
            ans.push_back(v);
            return;
        }
        
        for(int j=0;j<n;j++){
            if(valid(i,j,n) and (mask&(1<<j))==0){
                v[i][j] = 'Q';
                solve(i+1,mask|(1<<j),n);
                v[i][j] = '.';
            }
        }                
    }
    
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        string tp(n,'.');
        v.resize(n, string(tp));        
        solve(0,0,n);        
        return ans;
    }
};