#if defined(LOCAL)
#include <D:/cp/templates/my_template_compiled.hpp>
#else
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt")
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

void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  vc<vc<pii>> g(N);
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    g[x].pb(y, i);
    g[y].pb(x, i);
  }
  vi vis(N), a(N, 1);
  int cnt = 0;
  vi p;
  auto dfs = [&](auto &dfs, int u) -> void {
    vis[u] = 1;
    cnt += 1;
    for (auto [v, i] : g[u]) {
      if (!vis[v]) {
        dfs(dfs, v);
        if (a[v]) {
          if (a[u] && K >= 2)
            K -= 2;
          a[u] ^= 1;
          a[v] ^= 1;
          p.pb(i);
        }
      }
    }
  };
  rep(i, N) {
    if (vis[i]) {
      continue;
    }
    cnt = 0;
    dfs(dfs, i);
  }
  if (K) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
    cout << p.size() << "\n";
    for (auto i : p) {
      cout << i + 1 << " ";
    }
  }
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