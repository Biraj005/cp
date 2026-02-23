// Biraj Roy

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.hpp"
#else
#define debug(...)
#endif

#define     int         long long
#define     YN(f)       cout << ((f) ? "YES" : "NO") << '\n';
#define     all(a)      (a).begin(), (a).end()
#define     allr(a)     (a).rbegin(), (a).rend()
#define     Sum(a)      accumulate(all(a), 0LL)
#define     Max(a)     *max_element(all(a))
#define     Min(a)     *min_element(all(a))
#define     print(...)  cout << __VA_ARGS__ << '\n'
#define     bits(x)     __builtin_popcountll(x)
#define     msb(x)      (63 - __builtin_clzll(x))
#define     pb          push_back
#define     F           first
#define     S           second
#define     endl        '\n'
#define     yes         cout << "YES\n"
#define     no          cout << "NO\n"
#define     __          cout << '\n';

using      pii     =    pair<int, int>;
using      vi      =    vector<int>;
using      vvi     =    vector<vi>;
using      vvvi    =    vector<vvi>;
using      vpii    =    vector<pii>;
using      vb      =    vector<bool>;
using      vs      =    vector<string>;

template<typename T> using min_heap  = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using max_heap  = priority_queue<T>;


constexpr int INF   = (long long)4e18;
constexpr int INF2  = (int)2e9;
constexpr int MOD   = (int)1e9 + 7;
constexpr int MOD2  = (int)998244353;

int delR8[] = { -1, 0, 1, 0, 0, 1, 1, 1};
int delC8[] = { 0, 1, 0, -1, 1, -1, 0, 1};

template<typename T> istream& operator>>(istream &in, vector<T> &v) { for (T &x : v) in >> x; return in; }
template<typename T> ostream& operator<<(ostream &out, const vector<T> &v) { for (const T &x : v) out << x << " "; return out; }


template<class T> bool chmax(T &a, const T &b) {return (b > a) ? (a = b, 1) : 0;}
template<class T> bool chmin(T &a, const T &b) {return (b < a) ? (a = b, 1) : 0;}
int binpow(int a, int b) {int r = 1; a %= MOD; for (; b; b >>= 1, a = a * a % MOD)if (b & 1)r = r * a % MOD; return r;}
int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
int lcm(int a, int b) {return a / gcd(a, b) * b;}

struct BIT
{
    vector<long long> bit;
    int n;

    BIT(int size)
    {
        n = size + 1;
        bit.assign(n, 0);
    }
    void update(int i, long long val)
    {
        while (i < n)
        {
            bit[i] += val;
            i += (i & -i);
        }
    }
    long long query(int i) const
    {
        long long res = 0;
        while (i > 0)
        {
            res += bit[i];
            i -= (i & -i);
        }
        return res;
    }
};

void Solve(int tt) {
    debug(tt);
    // Your code here
    int N, Q;
    cin >> N >> Q;
    vi A(N);
    cin >> A;
    vvi adj(N);

    for (int i = 0; i + 1 < N; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int time = 0;

    vi in(N), out(N), lt(N + 2);
    BIT tree(N + 5);
    auto dfs = [&](auto && self, int u, int v)->void{

        in[u] = ++time;

        lt[in[u]] = A[u];
        tree.update(in[u], A[u]);

        for (auto &it : adj[u]) {
            if (it == v)continue;

            self(self, it, u);
        }

        out[u] = time;

    };

    dfs(dfs, 0, -1);

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {

            int u, value;
            cin >> u >> value;
            --u;
            int dif =  value - lt[in[u]];

            lt[in[u]] = value;
            tree.update(in[u], dif);
        } else {
            int u;
            cin >> u;
            --u;
            cout << tree.query(out[u])  - tree.query(in[u] - 1) << '\n';

        }
    }




}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("Error.txt", "w", stderr);
#endif
    //cout<<fixed<<setprecision(8);
    int tt = 1;
    // cin >> tt;
    for (int i = 1; i <= tt; i++) Solve(i);

    return 0;
}
