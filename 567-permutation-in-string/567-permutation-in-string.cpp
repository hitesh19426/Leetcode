class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        
        vector<int> freq(26, -1), window(26, -1);
        for(int i=0; i<(int)s1.size(); i++){
            freq[s1[i]-'a']++;
            window[s2[i]-'a']++;
        }
            
        for(int i=0; i+s1.size()-1<s2.size(); i++){
            if(i!=0){
                window[s2[i-1]-'a']--;
                window[s2[i+s1.size()-1]-'a']++;
            }
            
            if(freq == window) return true;
        }
        
        return false;
    }
};