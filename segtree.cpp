 #include <bits/stdc++.h>
using namespace std;

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
        : n(_n), st(4 * _n, _idNode), merge(_merge), idNode(_idNode) {}

    SegTree(const vector<NodeT>& arr,
            function<NodeT(const NodeT&, const NodeT&)> _merge,
            NodeT _idNode)
        : n((int)arr.size()), st(4 * arr.size(), _idNode),
          merge(_merge), idNode(_idNode) {
        build(1, 0, n - 1, arr);
    }

    void build(int p, int l, int r, const vector<NodeT>& arr) {
        if (l == r) {
            st[p] = arr[l];
            return;
        }
        int m = (l + r) / 2;
        build(p << 1, l, m, arr);
        build(p << 1 | 1, m + 1, r, arr);
        st[p] = merge(st[p << 1], st[p << 1 | 1]);
    }

    void update(int idx, const NodeT& val) {
        update(1, 0, n - 1, idx, val);
    }

    void update(int p, int l, int r, int idx, const NodeT& val) {
        if (l == r) {
            st[p] = val;
            return;
        }
        int m = (l + r) / 2;
        if (idx <= m)
            update(p << 1, l, m, idx, val);
        else
            update(p << 1 | 1, m + 1, r, idx, val);
        st[p] = merge(st[p << 1], st[p << 1 | 1]);
    }

    NodeT query(int L, int R) {
        return query(1, 0, n - 1, L, R);
    }

    NodeT query(int p, int l, int r, int L, int R) {
        if (R < l || r < L) return idNode;
        if (L <= l && r <= R) return st[p];
        int m = (l + r) / 2;
        return merge(query(p << 1, l, m, L, R),
                     query(p << 1 | 1, m + 1, r, L, R));
    }
};
