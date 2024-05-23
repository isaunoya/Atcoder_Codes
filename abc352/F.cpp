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
  vc<vi> G(N, vi(N));
  rep(i, M) {
    int a, b, c;
    cin >> a >> b >> c, --a, --b;
    G[a][b] = c;
    G[b][a] = -c;
  }
  rep(b, N) rep(a, N) rep(c, N) if (G[a][b] && G[b][c]) {
    G[a][c] = G[a][b] + G[b][c];
  }

  vi beg(N, 1);

  rep(i, N) {
    if (!beg[i])
      continue;
    rep(j, N) if (G[i][j]) { beg[j] = 0; }
  }

  vi mn(N), mx(N), msk(N);

  rep(x, N) {
    rep(i, N) if (G[i][x] || i == x) cmin(mn[x], G[i][x]), cmax(mx[x], G[i][x]);
    rep(i, N) if (G[i][x] || i == x) msk[x] |= 1 << (G[i][x] - mn[x]);
  }

  // debug(mn, mx, msk);

  rep(x, N) {
    vi vis(N);
    rep(i, N) if (G[i][x] || i == x) vis[i] = 1;
    vi f(1 << N, -1);
    f.back() = 0;
    int ans = -1;
    int cnt = 0;

    for (int s = (1 << N) - 1; s > 0; s--) {
      if (f[s] == -1) {
        continue;
      }
      int i = f[s];
      while (i < N && (vis[i] || !beg[i])) {
        i += 1;
      }

      if (i == N) {
        i = x;
      }

      for (int j = 0; j + mx[i] - mn[i] < N; j++) {
        int m = msk[i] << j;
        if ((s & m) == m) {
          f[s ^ m] = i + 1;

          if (i == x) {
            ans = j - mn[x] + 1;
            cnt++;
          }
        }
      }
    }

    if (cnt > 1) {
      ans = -1;
    }

    cout << ans << " \n"[x + 1 == N];
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