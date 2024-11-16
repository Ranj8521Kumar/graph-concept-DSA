#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    //Function for DFS travesal
    void dfs(int startNode, const vector<vector<int>> &adj, vector<int> &ls, vector<int> &vis){
        vis[startNode] = 1;
        ls.push_back(startNode);
        
        for(auto it: adj[startNode]){
            if(!vis[it]){
                vis[it] = 1;
                dfs(it, adj, ls, vis);
            }
        }
    }
  
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> ls;
        vector<int> vis(n, 0);
        int startNode = 0;
        dfs(startNode, adj, ls, vis);
        
        return ls;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends