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
  vc<string> grid(N);
  rep(i, N) { cin >> grid[i]; }

  vc<vi> used(N, vi(M));

  vc<vi> vis(N, vi(M));
  auto bfs = [&](int s, int t) {
    vc<pii> q{{s, t}};
    rep(q.size()) {
      auto [x, y] = q[i];
      bool ok = true;
      if (vis[x][y])
        continue;
      vis[x][y] = 1;
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          if (dx * dx + dy * dy == 1) {
            int nx = x + dx;
            int ny = y + dy;
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
              if (grid[nx][ny] == '#') {
                ok = false;
              }
            }
          }
        }
      }
      if (!ok)
        continue;
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          if (dx * dx + dy * dy == 1) {
            int nx = x + dx;
            int ny = y + dy;
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
              if (grid[nx][ny] == '.') {
                if (!vis[nx][ny])
                  q.pb(nx, ny);
              }
            }
          }
        }
      }
    }
    int cnt = sz(q);
    for (auto [x, y] : q) {
      vis[x][y] = 0;
      used[x][y] = 1;
    }
    return cnt;
  };

  int ans = 0;
  rep(i, N) {
    rep(j, M) {
      if (grid[i][j] == '#' || used[i][j]) {
        continue;
      }
      int cur = bfs(i, j);
      ans = max(ans, cur);
    }
  }
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