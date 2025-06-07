class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& conn : connections) {
            int from = conn[0], to = conn[1];
            graph[from].push_back({to, 1}); 
            graph[to].push_back({from, 0}); 
        }

        vector<bool> visited(n, false);
        int changes = 0;

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (auto& [neighbor, needsChange] : graph[node]) {
                if (!visited[neighbor]) {
                    changes += needsChange;
                    dfs(neighbor);
                }
            }
        };

        dfs(0); 

        return changes;
    }
};
