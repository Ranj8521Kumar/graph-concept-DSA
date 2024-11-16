#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int>& vis, const vector<vector<int>>& adjLs){
        vis[node] = 1;

        for(auto it: adjLs[node]){
            if(!vis[it]){
                vis[it] = 1;
                dfs(it, vis,  adjLs);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjLs(n + 1);

        //changes from adjancy matrix to  adjancy Lisy
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j] && i!=j){
                    adjLs[i+1].push_back(j+1);
                    adjLs[j+1].push_back(i+1);
                }
            }
        }

        vector<int> vis(n+1, 0);
        int count = 0;

        for(int i = 1; i<=n; i++){
            if(vis[i] == 0){
                count++;
                dfs(i, vis, adjLs);
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> isConnected(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> isConnected[i][j];
            }
        }
        Solution obj;
        int ans = obj.findCircleNum(isConnected);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends