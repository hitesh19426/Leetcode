class Solution {
public:
    bool isStrobogrammatic(string s) {
        vector<char> pairs{'0', '1', '|', '|', '|', '|', '9', '|', '8', '6'};
        for(int low=0, high=s.size()-1; low <= high; low++, high--){
            if(pairs[s[low]-'0'] != s[high])
                return false;
        }
        return true;
    }
};