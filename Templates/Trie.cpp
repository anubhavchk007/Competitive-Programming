class Node {
public:
    bool end;
    vector<Node*> child;
    Node() : end(false), child(26, nullptr) {}
};

class Trie {
public:    
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(const string& word) {
        Node* current = root;
        for (char x : word) {
            if (not current->child[x - 'a'])
                current->child[x - 'a'] = new Node();
            current = current->child[x - 'a'];
        }
        current->end = true;
    }

    bool search(const string& word) {
        Node* current = root;
        for (char x : word) {
            if (not current->child[x - 'a'])
                return false;
            current = current->child[x - 'a'];
        }
        return current->end;
    }

    bool isPrefix(const string& word) {
        Node* current = root;
        for (char x : word) {
            if (not current->child[x - 'a'])
                return false;
            current = current->child[x - 'a'];
        }
        return true;
    }

    ~Trie() {
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
