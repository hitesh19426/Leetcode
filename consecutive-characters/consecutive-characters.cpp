class Solution {
public:
    int maxPower(string s) {
        int count = 1, max_count = 1, n = s.size();
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]){
                count++;
                max_count = max(max_count, count);
            }
            else{
                count = 1;
            }
        }
        
        return max_count;
    }
};