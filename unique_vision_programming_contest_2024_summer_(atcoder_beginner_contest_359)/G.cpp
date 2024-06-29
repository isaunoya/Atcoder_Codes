#if defined(LOCAL)
#include <D:/cp/templates/my_template_compiled.hpp>
#else
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define debug(...) 42
#define rep1(a) for (auto i = 0; i < a; i++)
#define rep2(i, a) for (auto i = 0; i < a; i++)
#define rep3(i, a, b) for (auto i = a; i < b; i++)
#define rep4(i, a, b, c) for (auto i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define pb emplace_back
using namespace std;
template <typename T, typename T2> void cmin(T &x, const T2 &y) {
  x = x < y ? x : y;
}
template <typename T, typename T2> void cmax(T &x, const T2 &y) {
  x = x > y ? x : y;
}
template <typename T> using vc = vector<T>;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
mt19937 rng(time(NULL));
const int INF = 1000000000;
const ll LNF = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define fi first
#define se second
#endif
struct lowest_common_ancestor {
  vector<vector<int>> g;
  vector<int> dep;
  vector<int> dfn;
  vector<int> out;
  vector<int> fa;
  vector<vector<int>> f;
  int n;
  int Index;
  int LG;
  void dfs(int u) {
    dfn[u] = Index++;
    for (auto v : g[u]) {
      if (dfn[v] == -1) {
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs(v);
      }
    }
    out[u] = Index;
  }

  bool inside(int u, int x) { return dfn[x] <= dfn[u] && dfn[u] < out[x]; }
  int lca(int x, int y) {
    if (inside(x, y)) {
      return y;
    } else if (inside(y, x)) {
      return x;
    } else {
      for (int i = LG - 1, t; i >= 0; i--) {
        if (f[i][x] != -1 && !inside(y, t = f[i][x])) {
          x = t;
        }
      }
      return f[0][x];
    }
  }
  int distance(int x, int y) { return dep[x] + dep[y] - 2 * dep[lca(x, y)]; }
  lowest_common_ancestor(const vector<vector<int>> &graph, int root = 0)
      : g(graph) {
    n = graph.size();
    dep.resize(n, 0);
    dfn.resize(n, -1);
    out.resize(n);
    fa.resize(n, -1);
    LG = __lg(n) + 1;
    f.resize(LG);
    Index = 0;
    dfs(root);
    f[0] = fa;
    for (int j = 1; j < LG; j++) {
      for (int i = 0; i < n; i++) {
        if (f[j - 1][i] == -1) {
          f[j].emplace_back(-1);
        } else {
          f[j].emplace_back(f[j - 1][f[j - 1][i]]);
        }
      }
    }
  }
  int operator()(int x, int y) { return lca(x, y); }
};

void solve() {
  int N;
  cin >> N;
  vc<vi> g(N);
  rep(i, N - 1) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].pb(v);
    g[v].pb(u);
  }

  vi A(N);
  rep(i, N) cin >> A[i], --A[i];

  lowest_common_ancestor lca(g);

  vc<vi> group(N);
  rep(i, N) group[A[i]].pb(i);

  vi s(N);
  ll ans = 0;
  auto get = [&](vi &list, int col) {
    if (list.empty())
      return;
    int n = sz(list);
    if (n <= 300) {
      rep(i, n) rep(j, i + 1, n) ans += lca.distance(list[i], list[j]);
    } else {
      auto dfs = [&](auto &dfs, int u, int p) -> void {
        if (A[u] == col) s[u] = 1;
        else s[u] = 0;
        for (auto v : g[u]) {
          if (v == p) continue;
          dfs(dfs, v, u);
          ans += 1ll * s[v] * (n - s[v]);
          s[u] += s[v];
        }
      };
      dfs(dfs, 0, -1);
    }
  };
  
  rep(i, N) { get(group[i], i); }

  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}