class Solution {
public:
    int removePalindromeSub(string &s) {
        bool val = true;
        int n = s.size();
        int i=0,e=n-1;
        
        while(i<e){
            if(s[i]==s[e]){
                i++;
                e--;
            }
            else{
                return 2;
            }
        }
        
        return 1;
    }
};