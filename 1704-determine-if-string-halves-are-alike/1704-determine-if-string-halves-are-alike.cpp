class Solution {
    bool isvowel(char ch){
        vector<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(char c: vowels){
            if(c == ch)
                return true;
        }
        return false;
    }
    int countVowels(string &s, int low, int high){
        int count = 0;
        for(int i=low; i<=high; i++){
            count += isvowel(s[i]);
        }
        return count;
    }
public:
    bool halvesAreAlike(string s) {
        return countVowels(s, 0, s.size()/2-1) == countVowels(s, s.size()/2, s.size()-1);
    }
};