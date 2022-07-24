class Solution {
public:
    string frequencySort(string s) {
        int count[128] = {};
        for(char c: s)
            count[c]++;
        
        map<int, string, greater<int>> map;
        for(int i=0; i<128; i++){
            if(count[i])
                map[count[i]] += string(count[i], static_cast<char>(i));
        }
        
        string ans = "";
        for(auto &[x, str]: map)
            ans += str;
    
        return ans;
    }
};