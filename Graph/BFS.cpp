vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        vector<int> bfsNodes;
        vector<int> visited(V, 0);
        
        visited[0] = 1;
        q.push(0);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            bfsNodes.push_back(node);
            
            for(auto &it: adj[node]){
                if(!visited[it]){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfsNodes;
    }
