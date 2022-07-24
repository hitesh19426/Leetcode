class TopVotedCandidate {
    vector<int> leading, times;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) : times(times) {
        leading.resize(persons.size());
        vector<int> count(persons.size(), 0);
        
        for(int i=0; i<times.size(); i++){
            count[persons[i]]++;
            if(i==0 || count[persons[i]] >= count[leading[i-1]])
                leading[i] = persons[i];
            else
                leading[i] = leading[i-1];
        }
    }
    
    int q(int t) {
        return leading[upper_bound(times.begin(), times.end(), t) - times.begin() - 1];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */