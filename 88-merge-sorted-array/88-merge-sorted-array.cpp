class Solution {
public:
    void merge(vector<int>& v, int m, vector<int>& v2, int n) {
        int j = m-1;
        for(int i=m+n-1;i>=n;i--){
            v[i]= v[j];
            j--;
        }
        
        int i=0,k=0;
        j=n;
        
        while(j<m+n and k<n){
            if(v[j]<v2[k]){
                v[i] = v[j];
                j++;
            }
            else{
                v[i] = v2[k];
                k++;
            }
            i++;
        }
        
        while(j<m+n){
            v[i] = v[j];
            j++;
            i++;
        }
        
        while(k<n){
            v[i] = v2[k];
            k++;
            i++;
        }        
    }
};