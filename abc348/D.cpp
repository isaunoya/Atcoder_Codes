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
  int H, W;
  cin >> H >> W;
  vc<string> A(H);
  rep(H) cin >> A[i];
  int N;
  cin >> N;
  vc<vi> grid(H, vi(W));
  rep(i, N) {
    int x, y, z;
    cin >> x >> y >> z, --x, --y;
    grid[x][y] = z;
  }
  vc<vi> dp(H, vi(W, -1));
  vc<pii> q;
  rep(i, H) rep(j, W) if (A[i][j] == 'S') {
    dp[i][j] = 0;
    q.emplace_back(i, j);
  }
  rep(q.size()) {
    auto [x, y] = q[i];
    if (A[x][y] == 'T') {
      cout << "Yes\n";
      return;
    }
    if (dp[x][y] < grid[x][y]) {
      dp[x][y] = grid[x][y];
    }
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        if (dx * dx + dy * dy == 1) {
          int nx = x + dx;
          int ny = y + dy;
          if (!(0 <= nx && nx < H && 0 <= ny && ny < W)) {
            continue;
          }
          if (A[nx][ny] == '#')
            continue;
          if (dp[x][y] - 1 > dp[nx][ny]) {
            dp[nx][ny] = dp[x][y] - 1;
            q.pb(nx, ny);
          }
        }
      }
    }
  }
  cout << "No\n";
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