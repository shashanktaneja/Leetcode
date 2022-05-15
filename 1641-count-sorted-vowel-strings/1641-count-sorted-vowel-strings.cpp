class Solution {
public:
    int solve(int n,char cur){
        if(n==0){
            return 1;
        }
        
        int ans = 0;
        
        for(char ch = cur;ch<='e';ch++){
            ans += solve(n-1,ch);
        }
        
        return ans;
    }
    
    int countVowelStrings(int n) {
        int ans = solve(n,'a');        
        return ans;
    }
};