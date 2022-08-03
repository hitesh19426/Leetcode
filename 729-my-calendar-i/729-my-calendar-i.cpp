class MyCalendar {
    set<pair<int, int>> intervals;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto right = intervals.lower_bound({start, end-1});
        if(right != intervals.end() && right->first <= end-1)
            return false;
        if(right != intervals.begin() && (--right)->second >= start)
            return false;
        
        intervals.insert({start, end-1});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */