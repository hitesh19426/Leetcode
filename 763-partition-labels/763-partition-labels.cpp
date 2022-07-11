class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, -1);
        for(int i=0; i<s.size(); i++)
            last[s[i]-'a'] = i;
        
        int start = 0, end = last[s[0]-'a'];
        vector<int> ans;
        for(int i=0; i<s.size(); i++){
            end = max(end, last[s[i]-'a']);
            if(i == end){
                ans.push_back(i - start + 1);
                start = i+1, end = -1;
            }
        }
        
        return ans;
    }
};