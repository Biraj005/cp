class SegmentTree {
    int n;
    vector<pair<int, int>> tree; // {minValue, index}

public:
    SegmentTree(const vector<int> &a) {
        n = a.size();
        tree.resize(4 * max(1LL, n));
        if (n) build(a, 0, 0, n - 1);
    }

    void build(const vector<int> &a, int node, int l, int r) {
        if (l == r) {
            tree[node] = {a[l], l};
            return;
        }
        int mid = (l + r) / 2;
        build(a, 2 * node + 1, l, mid);
        build(a, 2 * node + 2, mid + 1, r);
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int idx, int val) {
        updateUtil(0, 0, n - 1, idx, val);
    }

    void updateUtil(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = {val, l};
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            updateUtil(2 * node + 1, l, mid, idx, val);
        else
            updateUtil(2 * node + 2, mid + 1, r, idx, val);
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }

    pair<int, int> query(int ql, int qr) {
        if (n == 0 || ql > qr) return {INF, -1};
        return queryUtil(0, 0, n - 1, ql, qr);
    }

    pair<int, int> queryUtil(int node, int l, int r, int ql, int qr) {
        if (qr < l || ql > r)
            return {INF, -1};
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        auto left = queryUtil(2 * node + 1, l, mid, ql, qr);
        auto right = queryUtil(2 * node + 2, mid + 1, r, ql, qr);
        return min(left, right);
    }
};
