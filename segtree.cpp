#include <bits/stdc++.h>
using namespace std;

class segTree
{
    vector<int> seg;
    int size;

    void build(int root, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            seg[root] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(root * 2 + 1, low, mid, arr);
        build(root * 2 + 2, mid + 1, high, arr);
        seg[root] = min(seg[2 * root + 1], seg[2 * root + 2]);
    }

    int query(int root, int low, int high, int l, int r)
    {
        if (l > high || r < low)
            return INT_MAX;
        if (low >= l && high <= r)
            return seg[root];

        int mid = (low + high) / 2;
        int left = query(2 * root + 1, low, mid, l, r);
        int right = query(2 * root + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    void update(int root, int low, int high, int idx, int val)
    {
        if (low == high)
        {
            seg[root] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (idx <= mid)
            update(2 * root + 1, low, mid, idx, val);
        else
            update(2 * root + 2, mid + 1, high, idx, val);

        seg[root] = min(seg[2 * root + 1], seg[2 * root + 2]);
    }

public:
    segTree(int n)
    {
        seg.resize(4 * n);
        size = n;
    }

    void build(vector<int> &arr)
    {
        build(0, 0, size - 1, arr);
    }

    int query(int l, int r)
    {
        return query(0, 0, size - 1, l, r);
    }

    void update(int idx, int val)
    {
        update(0, 0, size - 1, idx, val);
    }
};
