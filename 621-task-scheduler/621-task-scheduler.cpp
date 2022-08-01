struct Job{
    int ready_time, count, task;
    Job(int time, int count, int task) : ready_time(time), count(count), task(task) {}
    bool operator<(const Job& other) const {
        return count < other.count;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count[26] = {};
        for(char& task: tasks)
            count[task-'A']++;
        
        priority_queue<Job> ready;
        queue<Job> waiting;
        for(int i=0; i<26; i++){
            if(count[i] > 0)
                ready.push(Job(-1, count[i], i));
        }
        
        int time = 0;
        while(!ready.empty() || !waiting.empty()){
            while(!waiting.empty() && waiting.front().ready_time == time){
                ready.push(waiting.front());
                waiting.pop();
            }
            
            if(ready.empty()){
                time = waiting.front().ready_time;
                continue;
            }
            
            auto top = ready.top();
            ready.pop();
            
            if(top.count > 1){
                waiting.push(Job(time + n+1, top.count-1, top.task));
            }
            time++;
        }
        
        return time;
    }
};