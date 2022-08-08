class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses, rem = n;
        vector<int> inorder(n, 0);
        vector<vector<int>> graph(n, vector<int>());
        
        for(auto edge: prerequisites){
            graph[edge[0]].push_back(edge[1]);
            inorder[edge[1]]++;
        }
        
        queue<int> queue;
        for(int i=0; i<n; i++){
            if(inorder[i] == 0){
                queue.push(i);    
            }
        }
        
        while(!queue.empty()){
            auto pt = queue.front();
            queue.pop();
            rem--;
            
            for(int v: graph[pt]){
                inorder[v]--;
                if(inorder[v] == 0){
                    queue.push(v);
                }
            }
        }
        
        return rem == 0;
    }
};

/*
TC = O(V+E)
SC = O(V+E)

*/