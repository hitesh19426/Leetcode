class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mcount(26, 0), rcount(26, 0);
        for(char c: ransomNote)
            rcount[c-'a']++;
        for(char c: magazine)
            mcount[c-'a']++;
        for(int i=0; i<26; i++){
            if(mcount[i] < rcount[i])
                return false;
        }
        return true;
    }
};