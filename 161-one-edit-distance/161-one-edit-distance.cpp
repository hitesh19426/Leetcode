class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.empty())
            return t.size() == 1;
        if(t.empty())
            return s.size() == 1;
        if(s.length() < t.length()-1 || s.length() > t.length()+1)
            return false;
        
        if(s.length() == t.length()){
            int count = 0;
            for(int i=0; i<s.length(); i++)
                count += s[i] != t[i];
            return count == 1;
        }
        
        if(s.length() == t.length()+1){
            int i = 0;
            while(i<t.length() && s[i] == t[i])
                i++;
            while(i<t.length() && s[i+1] == t[i])
                i++;
            return i == t.length();
        }
        
        int i = 0;
        while(i<s.length() && s[i] == t[i])
            i++;
        while(i<s.length() && s[i] == t[i+1])
            i++;
        return i == s.length();
    }
};