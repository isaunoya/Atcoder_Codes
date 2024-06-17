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

void solve() {
  int N, M;
  cin >> N >> M;

  vector<vector<pair<int, int>>> G(N);
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    G[a].pb(b, -c);
    G[b].pb(a, c);
  }

  vector<int> vis(N, -1), d(N);

  vector<int> K;
  for (int i = 0; i < N; i++) {
    d[i] = 0;
    vis[i] = i;
    vector<int> q{i};
    for (int j = 0; j < (int)q.size(); j++) {
      int u = d[j];
      for (auto [v, c] : G[u]) {
        if (vis[v] == -1) {
          vis[v] = i;
          d[v] = d[u] + c;
          q.push_back(v);
        }
      }
    }

    int mn = 0;
    for (int j : q) {
      mn = min(mn, d[j]);
    }

    int msk = 0;
    for (int j : q) {
      msk |= 1 << (d[j] - mn);
    }

    K.push_back(msk);
  }

  vector<int> dp(1 << N);

  for (int i = 0; i < (int)K.size(); i++) {
    for (int j = 0; j < 1 << N; j++) {
      dp[j] = 0;
    }
    dp[0] = 1;
    for (int j = 0; j < (int)K.size(); j++) {
      if (i != j) {
        
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}