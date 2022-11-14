class Solution {
public:
    string reverseWords(string &s) {
        int i=0;
        int n = s.size();
        string ans;
        string cur="";
        vector<string> v;
        
        while(i<n){
            if(s[i]==' '){
                if(cur!=""){
                    v.push_back(cur);
                }
                cur="";
            }
            else{
                cur+=s[i];
            }
            i++;
        }
        
        if(cur!=""){
            v.push_back(cur);
        }
        
        reverse(v.begin(),v.end());
        
        for(int j=0;j<(v.size())-1;j++){
            ans+=v[j];
            ans+=" ";
        }
        ans+=v[(v.size())-1];
        
        return ans;
    }
};