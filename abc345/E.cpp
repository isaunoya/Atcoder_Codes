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


// to be fixed
void solve() {
  int N, K;
  cin >> N >> K;
  pll null(-LNF, -1);
  vc<pll> f(K + 1, null), g(K + 1, null);
  f[0] = g[0] = {0, -1};
  rep(i, N) {
    int c, v;
    cin >> c >> v;
    vc<pll> nf(K + 1, null), ng(K + 1, null);
    rep(j, K) nf[j + 1] = f[j], ng[j + 1] = g[j];
    rep(j, K + 1) {
      vc<pll> cur{nf[j], ng[j]};
      for (auto [val, col] : {f[j], g[j]}) {
        if (col != c) {
          cur.emplace_back(val + v, c);
        }
      }
      sort(all(cur), greater<>()), cur.resize(unique(all(cur)) - cur.begin());
      nf[j] = cur[0], ng[j] = cur.size() > 1 ? cur[1] : null;
    }
    f.swap(nf), g.swap(ng);
    // debug(f, g);
  }
  if (f[K].fi < 0) {
    cout << -1 << "\n";
  } else {
    cout << f[K].fi << "\n";
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