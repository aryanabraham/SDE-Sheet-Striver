//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    void dfsTraversal(int node, vector<bool> &visited, vector<int> &dfsVertices, vector<int> adj[]){
        visited[node] = true;
        dfsVertices.push_back(node);
        
        for(auto &it: adj[node]){
            if(!visited[it]){
                dfsTraversal(it, visited, dfsVertices, adj);
            }
        }
    }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> dfsVertices;
        vector<bool> visited(V, false);
        
        dfsTraversal(0, visited, dfsVertices, adj);
        return dfsVertices;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
