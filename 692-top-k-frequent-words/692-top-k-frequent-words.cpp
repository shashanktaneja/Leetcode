struct compare{
    bool operator()(pair<int,string> &p1,pair<int,string> &p2){
        if(p1.first==p2.first){
            return p1.second>p2.second;
        }

        return p1.first<p2.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& v, int k) {
        int n = v.size();
        unordered_map<string,int> mp;
        vector<string> ans;
        
        for(int i=0;i<n;i++){
            mp[v[i]]++;
        }
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare> pq;
        
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        
        for(int i=0;i<k;i++){
            pair<int,string> cur = pq.top();
            pq.pop();
            ans.push_back(cur.second);
        }
        
        
        return ans;
    }
};