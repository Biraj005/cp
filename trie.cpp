struct Node {
    Node* Links[26];
    bool flag = false;

    bool isContain(char ch) {
        return Links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        Links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return Links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(const string &word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->isContain(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool search(const string &word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->isContain(ch))
                return false;
            node = node->get(ch);
        }
        return node->isEnd();
    }
};

