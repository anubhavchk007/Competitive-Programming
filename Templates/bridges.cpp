class Bridges {
    public:
    int n, m, timer = 0;
    vector<vector<int>> g;
    vector<int> vis, in, low;
    vector<pair<int, int>> bridges;
    Bridges(int n, vector<vector<int>> g) {
        this->n = n;
        this->g = g;
        vis.resize(n + 1), low.resize(n + 1), in.resize(n + 1);
        m = g.size();
    }
    void dfs (int node, int par) {
        vis[node] = 1;
        in[node] = low[node] = timer++;
        for (int child : g[node]) {
            if (child == par) continue;
            if (vis[child]) {
                low[node] = min(low[node], in[child]);
            } else {
                dfs(child, node);
                if (low[child] > in[node]) {
                    bridges.push_back({node, child});
                }
                low[node] = min(low[node], low[child]);
            }
        }
    }
    vector<pair<int, int>> get () {
        for (int i = 1; i <= n; i++) {
            if (not vis[i]) {
                dfs(i, -1);
            }
        }
        return bridges;
    }
};
