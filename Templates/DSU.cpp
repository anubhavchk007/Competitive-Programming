class DSU {
public:
    vector<int> parent, size;
    int connected;
    DSU(int n) {
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
