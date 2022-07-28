class Solution {
public:
    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
        unordered_set<string> dict(features.begin(), features.end());   // make dict of features so we search features easily
        unordered_map<string, int> count;   // feature, count
        
        for(auto &response: responses){
            unordered_set<string> unique_words_in_response;
            stringstream ss(response);      // use string stream to separate words
            string word;
            
            while(ss >> word){
                unique_words_in_response.insert(word);  // insert all words from response into a set to get unique words
            }
            
            // for each word, check if there is a feature with same name, if it is, increase count of that feature
            for(auto &word: unique_words_in_response){
                if(dict.find(word) != dict.end())
                    count[word]++;
            }
        }
        
        vector<vector<int>> buckets(responses.size()+1);
        for(int i=0; i<features.size(); i++)
            buckets[count[features[i]]].push_back(i);
        
        vector<string> ans;
        for(int i=buckets.size()-1; i>=0; i--){
            for(int& ind: buckets[i])
                ans.push_back(features[ind]);
        }
        
        return ans;
    }
};
/*
TC(F, R, MFL, MRL) = F*MFL + R*(MRL) + F*R
SC(F, R, MFL, MRL) = F*MFL + R*(MRL)
*/