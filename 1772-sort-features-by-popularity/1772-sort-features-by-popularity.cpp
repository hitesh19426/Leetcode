class Solution {
public:
    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
        unordered_set<string> dict(features.begin(), features.end());
        unordered_map<string, int> count;
        
        for(auto &response: responses){
            unordered_set<string> unique_words_in_response;
            stringstream ss(response);
            string word;
            
            while(ss >> word){
                unique_words_in_response.insert(word);
            }
            
            for(auto &word: unique_words_in_response){
                if(dict.find(word) != dict.end())
                    count[word]++;
            }
        }
        
        stable_sort(features.begin(), features.end(), [&count](const auto &a, const auto &b) -> bool {
            return count[a] > count[b];
        });
        
        return features;
    }
};