class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int start = 0;
        for(int i=0; i<=s.size(); i++){
            if(i == s.size() || s[i] == ' '){
                reverse(s.begin()+start, s.begin()+i);
                start = i+1;
            }
        }
    }
};