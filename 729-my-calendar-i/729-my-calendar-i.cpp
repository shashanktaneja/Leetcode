class MyCalendar {
public:
    set<pair<int,int>> s;
    
    MyCalendar() {
        s.clear();
    }
    
    bool book(int st, int e) {
        for(auto x:s){
            int tp1 = x.first,tp2 = x.second;
            if(!((st<tp1 and e<=tp1) || (st>=tp2 and e>tp2))){
                return false;
            }
        }
        
        s.insert({st,e});
                
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */