class Solution {
    int id(int x, int y, int col){
        return x*col + y;
    }
    
    vector<vector<int>> make_graph(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> graph(m*n, vector<int>());
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] != 1){
                    
                    for(int x=i+1, y=j; x<=m; x++){
                        if(x==m || grid[x][y] == 1){
                            if(x-1 != i)
                                graph[id(i, j, n)].push_back(id(x-1, y, n));
                            break;
                        }
                    }
                    
                    for(int x=i-1, y=j; x>=-1; x--){
                        if(x==-1 || grid[x][y] == 1){
                            if(x+1 != i)
                                graph[id(i, j, n)].push_back(id(x+1, y, n));
                            break;
                        }
                    }
                    
                    for(int x=i, y=j+1; y<=n; y++){
                        if(y==n || grid[x][y] == 1){
                            if(y-1 != j)
                                graph[id(i, j, n)].push_back(id(x, y-1, n));
                            break;
                        }
                    }
                    
                    for(int x=i, y=j-1; y>=-1; y--){
                        if(y==-1 || grid[x][y] == 1){
                            if(y+1 != j)
                                graph[id(i, j, n)].push_back(id(x, y+1, n));
                            break;
                        }
                    }
                    
                }
            }
        }
        
        return graph;
    }
    
    int get_dist(int p1, int p2, int col){
        int x1 = p1/col, y1 = p1%col, x2 = p2/col, y2 = p2%col;
        return abs(x1-x2) + abs(y1-y2);
    }
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        auto graph = make_graph(maze);
        
        // for(int i=0; i<graph.size(); i++){
        //     for(int x: graph[i])
        //         cout << x << " ";
        //     cout << endl;
        // }
        int m = maze.size(), n = maze[0].size(), target = id(dest[0], dest[1], n);
        vector<int> dist(m*n, INT_MAX);
        set<pair<int, int>> minheap;
        
        dist[id(start[0], start[1], n)] = 0;
        minheap.insert({0, id(start[0], start[1], n)});
        
        while(!minheap.empty()){
            // auto pt = queue.front();
            // queue.pop();
            auto [curr_dist, ver] = *minheap.begin();
            minheap.erase(minheap.begin());
            
            if(ver == target)
                return curr_dist;
            
            for(auto &v: graph[ver]){
                int new_dist = curr_dist + get_dist(ver, v, n);
                if(dist[v] > new_dist){
                    minheap.erase({dist[v], v});
                    dist[v] = new_dist;
                    // queue.push(v);    
                    minheap.insert({dist[v], v});
                }
            }
        }
        
        return -1;
    }
};