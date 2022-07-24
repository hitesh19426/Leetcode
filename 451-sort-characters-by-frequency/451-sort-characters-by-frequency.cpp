class Solution {
public:
    string frequencySort(string s) {
        vector<int> count(128, 0);
        for(char c: s)
            count[c]++;
        
        sort(s.begin(), s.end(), [&count](auto &a, auto &b) -> bool {
            if(count[a] != count[b])
                return count[a] > count[b];
            return a < b;
        });
        
        return s;
    }
};