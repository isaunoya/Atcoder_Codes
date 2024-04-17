#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 42
#endif
#define rep(i, x, y) for (int i = x; i < y; i++)
#define eb emplace_back
using namespace std;
template <typename T, typename T2> void cmin(T &x, const T2 &y) {
  if (x > y)
    x = y;
}
template <typename T, typename T2> void cmax(T &x, const T2 &y) {
  if (x < y)
    x = y;
}
using ll = long long;
mt19937 rng(time(NULL));
const int inf = 1000000000;
const ll lnf = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> c(n);
  vector<vector<int>> v(n);

  for (int i = 0; i < n; i++) {
    cin >> c[i];
    int p;
    cin >> p;
    v[i].resize(p);
    rep(j, 0, p) cin >> v[i][j];
  }

  vector<double> dp(m + 1, 1e9);
  dp[m] = 0;
  for (int i = m - 1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      double res = c[j];
      int sz = sz(v[j]);
      double psb = 0;
      for (int k : v[j]) {
        if (k == 0) {
          psb += 1. / sz;
        } else {
          res += dp[min(m, i + k)] / sz;
        }
      }
      cmin(dp[i], res / (1 - psb));
    }
  }
  cout << fixed << setprecision(20) << dp[0] << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}