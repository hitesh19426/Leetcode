class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> masks;
        for(auto& word: words){
            int mask= 0;
            for(char &c: word)
                mask |= (1<<(c-'a'));
            masks.push_back(mask);
        }
        
        int ans = 0;
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                if((masks[i]&masks[j]) == 0)
                    ans = max(ans, (int)(words[i].size()*words[j].size()));
            }
        }
        return ans;
    }
};
/*
Time: O(n*len) + O(n*n)
Space: O(n)
*/