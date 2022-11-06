class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1){
            sort(s.begin(), s.end());
        }else{
            string ans = s;
            for(int i=1; i<s.size(); i++){
                string rotated = s.substr(i) + s.substr(0, i);
                if(rotated < ans)
                    ans = rotated;
            }
            s = ans;
        }
        
        return s;
    }
};