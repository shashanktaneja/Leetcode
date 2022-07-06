class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1){
            return n;
        }
        
        int ans = 1;
        int s=1,s2=1;
        int i=0;
        while(i<n-2){
            ans = s+s2;
            s = s2;
            s2 = ans;
            i++;
        }
        
        return ans;
    }
};