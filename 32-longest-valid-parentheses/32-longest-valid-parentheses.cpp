class Solution {
public:
    int longestValidParentheses(string &s) {
        int n =s.size();
        int ans = 0;
        
        stack<int> S;
        int cur = 0;
        S.push(-1);
        
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                S.push(i);
            }
            else{
                S.pop();
                if(S.empty()){
                    S.push(i);
                }
                else{
                    int cur = i-S.top();
                    ans = max(cur,ans);
                }
            }
        }
        
        return ans;
    }
};