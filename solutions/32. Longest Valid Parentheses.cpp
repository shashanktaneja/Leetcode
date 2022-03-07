class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        
        stack<int> s1;
        s1.push(-1);
        int ans = 0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                s1.push(i);
            }
            else{
                s1.pop();
                if(s1.empty()){
                    s1.push(i);
                }
                else{
                    int cur = i-s1.top();
                    ans = max(ans,cur);
                }
            }
        }
        
        return ans;
    }
};
