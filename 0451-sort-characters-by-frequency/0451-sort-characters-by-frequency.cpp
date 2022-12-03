class Solution {
public:
    string frequencySort(string s) {
        int freq[128] = {};
        for(char c: s)
            freq[c]++;
        
        sort(s.begin(), s.end(), [&freq](const auto &a, const auto &b) -> bool {
            if(freq[a] != freq[b])
                return freq[a] > freq[b];
            return a > b;
        });
    
        return s;
    }
};