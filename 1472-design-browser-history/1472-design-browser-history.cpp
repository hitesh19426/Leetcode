class BrowserHistory {
    int pos = 0, n = 1;
    vector<string> history;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
    }
    
    void visit(string url) {
        if(++pos == history.size())
            history.push_back(url), n++;
        else
            history[pos] = url, n = pos+1;
    }
    
    string back(int steps) {
        pos = max(0, pos - steps);
        return history[pos];
    }
    
    string forward(int steps) {
        pos = min(pos+steps, n-1);
        return history[pos];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */