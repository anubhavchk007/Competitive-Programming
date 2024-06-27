class Node {
public:
    bool end;
    vector<Node*> child;
    Node() : end(false), child(2, nullptr) {}
};

class BinaryTrie {
public:    
    int MAX = 31;
    Node* root;
    BinaryTrie() {
        root = new Node();
    }

    void insert(int num) {
        Node* current = root;
        for (int i = MAX; i >= 0; --i) {
            int x = (num >> i) & 1;
            if (not current->child[x])
                current->child[x] = new Node();
            current = current->child[x];
        }
        current->end = true;
    }

    int maxXOR(int num) {
        Node* current = root;
        int ans = 0;
        for (int i = MAX; i >= 0; --i) {
            int x = (num >> i) & 1;
            if (current->child[x ^ 1]) {
                ans += 1LL << i;
                x ^= 1;
            }
            current = current->child[x];
        }
        return ans;
    }

    ~BinaryTrie() {
        clear(root);
    }

    void clear(Node* node) {
        if (not node) return;
        for (auto &x : node->child) {
            clear(x);
        }
        delete node;
    }
};
