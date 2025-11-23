template <typename NodeT>
struct SegTree {
    int n;
    vector<NodeT> st;
    function<NodeT(const NodeT&, const NodeT&)> merge;
    NodeT idNode;

    SegTree() = default;

    SegTree(int _n,
            function<NodeT(const NodeT&, const NodeT&)> _merge,
            NodeT _idNode)
        : n(_n), st(4 * _n, _idNode),
          merge(_merge), idNode(_idNode) {}

    SegTree(const vector<NodeT>& arr,
            function<NodeT(const NodeT&, const NodeT&)> _merge,
            NodeT _idNode)
        : n(arr.size()), st(4 * arr.size(), _idNode),
          merge(_merge), idNode(_idNode) {
        build(0, 0, n - 1, arr);
    }

    void build(int p, int l, int r, const vector<NodeT>& arr) {
        if (l == r) {
            st[p] = arr[l];
            return;
        }
        int m = (l + r) >> 1;
        int L = 2 * p + 1;
        int R = 2 * p + 2;
        build(L, l, m, arr);
        build(R, m + 1, r, arr);
        st[p] = merge(st[L], st[R]);
    }

    void update(int idx, const NodeT& val) {
        update(0, 0, n - 1, idx, val);
    }

    void update(int p, int l, int r, int idx, const NodeT& val) {
        if (l == r) {
            st[p] = val;
            return;
        }
        int m = (l + r) >> 1;
        int L = 2 * p + 1;
        int R = 2 * p + 2;

        if (idx <= m) update(L, l, m, idx, val);
        else          update(R, m + 1, r, idx, val);

        st[p] = merge(st[L], st[R]);
    }

    NodeT query(int L, int R) {
        return query(0, 0, n - 1, L, R);
    }

    NodeT query(int p, int l, int r, int L, int R) {
        if (R < l || r < L) return idNode;
        if (L <= l && r <= R) return st[p];

        int m = (l + r) >> 1;
        int left = query(2*p + 1, l, m, L, R);
        int right = query(2*p + 2, m + 1, r, L, R);
        return merge(left, right);
    }
};
