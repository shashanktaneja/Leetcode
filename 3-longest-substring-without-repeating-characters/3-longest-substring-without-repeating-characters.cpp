class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        int n = s.size();
        int ans = 0;
        
        map<char,int> freq;
        
        int i=0,j=0,cur;
        while(j<n){
            if(freq[s[j]-'a']>0){
                cur = j-i;
                ans = max(ans,cur);
                while(i<j and freq[s[j]-'a']>0){
                    freq[s[i]-'a']--;
                    i++;
                }
            }
            freq[s[j]-'a']++;
            j++;
        }
        
        cur = n-i;
        ans = max(ans,cur);
        
        return ans;
    }
};