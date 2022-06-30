class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, -1);
        for(int i=0; i<s.size(); i++){
            last[s[i]-'a'] = i;
        }
        
        int max_index = last[s[0]-'a'], count = 0, last_partition = -1;
        vector<int> ans;
        for(int i=0; i<s.size(); i++){
            max_index = max(max_index, last[s[i]-'a']);
            if(i == max_index){
                ans.push_back(i-last_partition);
                last_partition = i;
            }
        }
        
        return ans;
    }
};