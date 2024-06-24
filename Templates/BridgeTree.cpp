class BridgeTree {
public:
    class Bridges { // finds all bridges and returns vector of pairs [u, v] (u < v)
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
                        bridges.push_back({min(node, child), max(node, child)});
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
    
    
    int n;
    vector<vector<int>> adj;
    vector<pair<int, int>> bridges;
    DSU d;
    BridgeTree(int n, vector<vector<int>> g, vector<pair<int, int>> edges) { // edges[i].first should be < edges[i].second
        this->n = n;
        Bridges b(n, g);
        bridges = b.get();
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
