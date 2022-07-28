class Solution {
    int countWords(string &sentence){
        int count = 0;
        for(char& c: sentence){
            if(c == ' ')
                count++;
        }
        return ++count;
    }
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> count;   // user -> count
        string maxWordUser = "";
        int maxMessageLength = 0;
        for(int i=0; i<messages.size(); i++){
            count[senders[i]] += countWords(messages[i]);
            if(count[senders[i]] > maxMessageLength)
                maxMessageLength = count[senders[i]], maxWordUser = senders[i];
            else if(count[senders[i]] == maxMessageLength){
                maxWordUser = max(maxWordUser, senders[i]);
            }
        }
        
        return maxWordUser;
    }
};