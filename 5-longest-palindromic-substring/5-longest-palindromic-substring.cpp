class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int max_len = 1;
        int low,high;
        int start = 0;

        for(int i=1;i<n;i++){
            //find the max even length palindrome
            low = i-1;
            high = i;
            while(low>=0 and high<n and s[low]==s[high]){
                if(high-low+1>max_len){
                    start = low;
                    max_len = high-low+1;
                }
                low--;
                high++;
            }

            //find the max odd length palindrome
            low = i-1;
            high = i+1;
            while(low>=0 and high<n and s[low]==s[high]){
                if(high-low+1>max_len){
                    start = low;
                    max_len = high-low+1;
                }
                low--;
                high++;
            }
        }

        string longest = s.substr(start,max_len);
        return longest;
    }
};