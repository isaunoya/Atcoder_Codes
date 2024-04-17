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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> a(n);
  vector<vector<int>> c(k);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
    c[a[i]].emplace_back(i);
  }
  string t(n, '0');
  for (int i = 0; i < k; i++) {
    int sz = sz(c[i]);
    rep(j, 0, sz) { t[c[i][j]] = s[c[i][(j - 1 + sz) % sz]]; }
  }
  cout << t << "\n";
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