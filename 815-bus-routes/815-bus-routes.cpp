class Solution {
    bool intersect(vector<set<int>>& routes_set, int i, int j){
        for(const int &x: routes_set[i]){
            if(routes_set[j].find(x) != routes_set[j].end())
                return true;
        }
        return false;
    }
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)
            return 0;
        vector<set<int>> routes_set(routes.size());
        for(int i=0; i<routes.size(); i++)
            routes_set[i] = set<int>(routes[i].begin(), routes[i].end());
        
        vector<int> dist(routes.size(), INT_MAX);
        queue<int> queue;
        for(int i=0; i<routes.size(); i++){
            if(routes_set[i].find(source) != routes_set[i].end()){
                queue.push(i);
                dist[i] = 0;
            }
        }
        
        while(!queue.empty()){
            auto ind = queue.front();
            queue.pop();

            if(routes_set[ind].find(target) != routes_set[ind].end())
                return dist[ind]+1;

            for(int i=0; i<routes_set.size(); i++){
                if(dist[i] == INT_MAX && intersect(routes_set, ind, i)){
                    queue.push(i);
                    dist[i] = dist[ind]+1;
                }
            }
        }
        
        return -1;
    }
};