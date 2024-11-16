#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0); //visited Arrayt
        vector<vector<int>> adj(n);

        //Build a undirected graph
        for(const auto &edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        //Build DFS travesal
        auto travesal = [&](int start, vector<int>& component){
            queue<int> q;
            q.push(start);

            vis[start] = 1;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                component.push_back(node);

                for(int neighbour: adj[node]){
                    if(!vis[neighbour]){
                        vis[neighbour] = 1;
                        q.push(neighbour);
                    }
                }
            }
        };

        //function for isCompete
        auto isComplete = [&](const vector<int>& component) -> bool {
            int Size = component.size();
            for(auto node: component){
                if(adj[node].size() != Size - 1){
                    return false;
                }
            }
            return true;
        };

        //Check all components
        int completeCount = 0;

        for(int i = 0; i<n; i++){
            if(!vis[i]){
                vector<int> component;
        
                travesal(i, component);
                if(isComplete(component)){
                    completeCount++;
                }
            }
        }
        return completeCount;
    }
};

//Main Function
int main(){
    Solution sol;
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}, {0, 3}, {3, 5}};
    cout<<sol.countCompleteComponents(n, edges)<<endl;
    return 0;
}