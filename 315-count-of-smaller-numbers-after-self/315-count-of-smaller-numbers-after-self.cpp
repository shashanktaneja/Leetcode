class Solution {
public:
    vector<int> ans;
    vector<pair<int,int>> v2;
    
    void merge(int s,int mid,int e){
        // cout<<s<<" "<<e<<endl;
        int i=s,j=mid+1;
        vector<pair<int,int>> temp;
        
        while(i<=mid and j<=e){
            if(v2[i].first<=v2[j].first){
                ans[v2[i].second] += (j-mid-1);
                temp.push_back({v2[i].first,v2[i].second});
                i++;
            }
            else{
                temp.push_back({v2[j].first,v2[j].second});
                j++;
            }
        }
        
        while(i<=mid){
            temp.push_back({v2[i].first,v2[i].second});
            ans[v2[i].second] += (j-mid-1);
            i++;
        }
        
        while(j<=e){
            temp.push_back({v2[j].first,v2[j].second});
            j++;            
        }
        
        for(int k=s;k<=e;k++){
            // cout<<v[k]<<" ";
            v2[k] = temp[k-s];
        }
        // cout<<endl;
        // cout<<s<<" "<<e<<endl;
        
    }
    
    void mergesort(int s,int e){
        if(s>=e){
            return;
        }
        
        int mid = (s+e)/2;
        mergesort(s,mid);
        mergesort(mid+1,e);
        
        merge(s,mid,e);
    }
    
    vector<int> countSmaller(vector<int>& v) {
        int n = v.size();
        ans.clear();
        v2.clear();
        
        for(int i=0;i<n;i++){
            v2.push_back({v[i],i});
            ans.push_back(0);
        }
        
        mergesort(0,n-1);
        
        return ans;
    }
};