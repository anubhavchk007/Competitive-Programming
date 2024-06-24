class BridgeTree {
public:
    vector<int> sz, in, low, vis;
    vector<pair<int, int>> bridges;
    vector<vector<int>> g;
    int timer, n;
    void find_bridges() { // stores all the bridges as vector of pairs [u, v] (u < v)
        timer = 0;
        vis.resize(n + 1), low.resize(n + 1), in.resize(n + 1), sz.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            if (not vis[i]) {
                bridge_dfs(i, -1);
            }
        }
    }
    void bridge_dfs (int node, int par) {
        vis[node] = sz[node] = 1;
        in[node] = low[node] = timer++;
        for (int child : g[node]) {
            if (child == par) continue;
            if (vis[child]) {
                low[node] = min(low[node], in[child]);
            } else {
                bridge_dfs(child, node);
                sz[node] += sz[child];
                if (low[child] > in[node]) {
                    bridges.push_back({min(node, child), max(node, child)});
                }
                low[node] = min(low[node], low[child]);
            }
        }

    }
    class DSU { // used to merge many nodes into one to create Bridge Tree
    public:
        vector<int> parent, size;
        int connected;
        void init (int n) {
            parent.resize(n + 1);
            iota(parent.begin(), parent.end(), 0);
            size.resize(n + 1, 1);
            connected = n;
        }
        int get(int x) {
            return parent[x] = (parent[x] == x ? x : get(parent[x]));
        }
        void unite(int x, int y) {
            x = get(x), y = get(y);
            if (x != y) {
                connected--;
                if (size[x] < size[y])
                    swap(x, y);
                parent[y] = x;
                size[x] += size[y];
                size[y] = 0;
            }
        }
    };
    
    
    vector<vector<int>> adj;    // adj represents BridgeTree
    DSU d;                      // whereas g represents original graph
    BridgeTree(int n, vector<vector<int>> g, vector<pair<int, int>> edges) { // edges[i].first should be < edges[i].second
        this->n = n;
        this->g = g;
        find_bridges();
        map<pair<int, int>, int> mp;
        for (auto x : bridges) {
            mp[x]++;
        }
        adj.resize(n + 1);
        d.init(n + 1);
        for (int i = 0; i < edges.size(); i++) {
            if (not mp[edges[i]]) {
                d.unite(edges[i].first, edges[i].second);
            }
        }
        for (int i = 0; i < edges.size(); i++) {
            if (mp[edges[i]]) {
                adj[d.get(edges[i].first)].push_back(d.get(edges[i].second));
                adj[d.get(edges[i].second)].push_back(d.get(edges[i].first));
            }
        }
    }
    int diameter() {
        vector<int> dist(n + 1, -1);
        dfs(d.get(1), 0, dist, 0);
        int mx = -1e9, endpoint;
        for (int i = 1; i <= n; i++) {
            if (dist[i] != -1) {
                if (dist[i] > mx) {
                    mx = dist[i];
                    endpoint = i;
                }
            }
        }
        for (auto &x : dist) x = -1;
        dfs(endpoint, 0, dist, 0);
        mx = -1e9;
        for (auto x : dist) {
            if (x != -1)
                mx = max(mx, x);
        }
        return mx;
    }
    
    void dfs (int node, int par, vector<int>& dist, int d) {
        dist[node] = d;
        for (int child : adj[node]) {
            if (child == par) continue;
            dfs(child, node, dist, d + 1);
        }
    }
};
